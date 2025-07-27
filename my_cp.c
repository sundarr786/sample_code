/*
 * Author: R Sundar
 *
 * Usage:  ./a.out source_file_path dest_file_path
 *
 * Compilation: gcc my_cp.c err_func.c
 *
 */


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "err_func.h"

#define MAX_FILEPATH_LEN 255
#define BUF_4K 4095




int main(int argc, char *argv[])
{
	int r_fd = -1;
	int w_fd = -1;
	int flags = 0;
	ssize_t num_read = 0;
	ssize_t num_write = 0;
	mode_t file_perm = 0;
	char buffer[BUF_4K + 1] = "";

	if (argc != 3) {
		usageErr("%s old_file new_file\n", argv[0]);
		
	}

	if (strncmp(argv[1], argv[2], MAX_FILEPATH_LEN) == 0)
		errExit("arguments are same, which lead to lost of file input: %s\n", argv[1]);


	if ((r_fd = open(argv[1], O_RDONLY)) == -1) 
		errExit("unable to open file: %s\n", argv[1]);

	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if ((w_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, file_perm)) == -1)  {
		close(r_fd);
		errExit("unable to open file: %s\n", argv[2]);
	}

	while ((num_read = read(r_fd, buffer, BUF_4K)) > 0) {
		if ((num_write = write(w_fd, buffer, num_read)) != num_read) {
			close(r_fd);
			close(w_fd);
			errExit("unable to write buffer, written len: %d read_len: %d", num_write, num_read);
		}
		memset(buffer, 0x0, sizeof(buffer));
	}
			
	
	close(r_fd);
	close(w_fd);
	
	printf("my copy success for %s to %s\n", argv[1], argv[2]);

	return 0;
}
