/*Author:    Sean Welsh
 * Date:     November 22, 2025
 * purpose:  Practice with fork() and recursively crawling through a directory
 *           in order to copy files from one directory to another and show a
 *           progress bar for how much has been completed
 */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <sys/wait.h>

#define BUFFER_SIZE 4096
#define BAR_WIDTH 50 // Length of the progress bar

static off_t calc_dir_size(off_t, char *); //calculates size of a directory
static void show_progress(off_t copied, off_t total); //shows progress bar
static void my_copy(char *, char *); //copys files from one directory to another



/*********** Main Function ************************/
int main(int argc, char *argv[]) {
	off_t src_size;
	if(argc != 3){
		fprintf(stderr, "Usage: %s <source> <destination> \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char *src_dir = argv[1];
	char *dest_dir = argv[2];

	src_size = calc_dir_size(0, src_dir); //calculates size of the src directory

	pid_t pid = fork();

	if(pid < 0){
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}else if(pid == 0){ //child fork
		sleep(1);  // Give parent time to create dest directory

		while(1){
			off_t dest_size = calc_dir_size(0, dest_dir); //calculates size of all the
																										//files that have been 
																										//copied far
			if(dest_size < src_size){
				show_progress(dest_size, src_size); //displays progress
			}else{
				show_progress(dest_size, src_size); //shows 100%
				printf("\nCopy complete\n");
				break;
			}
			usleep(200000); //suspends for 200000 microseconds
		}
		exit(0); //exits the child thread
	}else{
		my_copy(src_dir, dest_dir); //copies all files from one directory to another
		wait(NULL); //waits for child thread to close before closing
	}
	return 0;
}

/*
 * Descend through the hierarchy, starting at "path". Start by using lstat to
 * get stat data on "path" if it is not a directory then return the current 
 * total size + the size of the current file. If it is a directory get the 
 * dirent structure of the current path and use that to loop through and 
 * recursively call cal_dir_size for all the files in the current directory. 
 * Effectively getting the size of every file in the directory and adding them
 * together. Finally once done with the directory pointer close it.
 */
static off_t calc_dir_size(off_t total_size, char * path){
	struct stat statbuf;
	struct dirent *dirp;
	DIR *dp;

	if(lstat(path, &statbuf) < 0){
		perror("lstat error calc_dir_size");
		return total_size;
	}

	/*not a directory return total size+ size of current file */
	if(S_ISDIR(statbuf.st_mode) == 0)
		return(total_size + statbuf.st_size);

	/*error opening current directory just return the current total size*/
	if((dp = opendir(path)) == NULL){
		perror("can't open directory");
		return total_size;
	}

	/*loop through all entries in a directory and recursively calls calc_dir_size
	 * with each entry in the directory and captures the size of all files in
	 * the direcotry
	 */
	while((dirp = readdir(dp)) != NULL){
		if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
			continue;

		char full_path[PATH_MAX];

		snprintf(full_path, PATH_MAX, "%s/%s", path, dirp->d_name);

		total_size =calc_dir_size(total_size, full_path);
	}
	/*closes the DIR *dp pointer */
	if(closedir(dp)<0)
		perror("can't close directory");
	return(total_size);
}

/* shows a progress bar for how much data has been transfered to the new 
 * directory
 */
void show_progress(off_t copied, off_t total){
	double ratio = (double)copied / total;
	int filled = (int)(ratio * BAR_WIDTH);

	printf("\r[");
	for(int i = 0; i < BAR_WIDTH; i++){
		if(i < filled)
			printf("#");
		else
			printf("-");
	}
	printf("] %6.2f%%", ratio * 100);
	fflush(stdout);
}

/* recursively decends the src directory. if the current src_path is a directory
 * a new directory is made in the des_path that matches the src_path. If the
 * src_parth is a file then the file is copied from the src_path to the
 * dest_path
 */
void my_copy(char *src_path, char *dest_path){
	struct stat statbuf;
	struct dirent *dirp;
	DIR *dp;

	//get stat structure for src_path
	if(lstat(src_path, &statbuf) < 0){
		perror("lstat error for my_copy");
		return;
	}

	if(S_ISDIR(statbuf.st_mode) == 0){ // not a directory
		int src_fd = open(src_path, O_RDONLY); //open src_file and store its fd
		if(src_fd < 0){
			perror("Error opening ");
			return;
		}

		//open a dest_file and store its fd
		int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if(dest_fd < 0){
			perror("Error openeing destination file");
			close(src_fd);
			return;
		}

		char buffer[BUFFER_SIZE];
		ssize_t bytes_read, bytes_written;

		/*buffered read from src file and then write that buffer to the destination
		 * file
		 */
		while((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) >0){
			bytes_written = write(dest_fd, buffer, bytes_read);
			if(bytes_written < 0){
				perror("Error writing to destination file");
				break;
			}
		}
		//close src and dest fd
		close(src_fd);
		close(dest_fd);
		return;
	}

	/* if src_file was a directory this code executes.
	 * makes the destination directory if it does not exist. If it does exist
	 * does nothing and ignores the error EEXIST
	 */
	if(mkdir(dest_path, 0755) !=0 && errno != EEXIST){
		perror("can't create directory");
		return;
	}

	/*opens the src_path directory and saves to dp or prints an error and returns
	 * if it cant open the directory
	 */
	if((dp = opendir(src_path)) == NULL){
		perror("can't open directory");
		return;
	}

	/* loops through all the files in the src directory. For each file in the
	 * src directory it saves its path to new source and generates/updates the 
	 * path for the destination source. It then recursively calls my_copy with
	 * the newly updated paths.
	 */
	while((dirp = readdir(dp)) != NULL){
		if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
			continue;

		char new_src[PATH_MAX];
		char new_dest[PATH_MAX];

		snprintf(new_src, PATH_MAX, "%s/%s", src_path, dirp->d_name);
		snprintf(new_dest, PATH_MAX, "%s/%s", dest_path, dirp->d_name);

		my_copy(new_src, new_dest);
	}

	//closes the open directory pointers
	if(closedir(dp)<0)
		perror("can't close directory");
}
