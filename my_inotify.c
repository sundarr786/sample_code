/*
 * Author: R Sundar
 *
 * Description: inotify to test sample files for understanding.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/inotify.h>

#define BUF_LEN 64

int fd = -1;
int g_ffd = -1;

void cleanup(void)
{

	inotify_rm_watch(fd, g_ffd);
	if (fd!=-1 && fd)
		close(fd);
}

void display_event(struct inotify_event *event)
{
	if (event->mask & IN_MODIFY)
		printf("file modified\n");
	if (event->mask & IN_OPEN)
		printf("file opened\n");
	if (event->mask & IN_CREATE)
		printf("file created\n");
	if (event->mask & IN_DELETE)
		printf("file deleted\n");
	if (event->mask & IN_DELETE_SELF)
		printf("self file deleted\n");
	if (event->mask & IN_ACCESS)
		printf("file accessed\n");
	
	return;

}


int main()
{
	char *ptr = NULL;
	char buf[BUF_LEN] __attribute__ ((aligned(8)));
	int numread = 0;
	struct inotify_event *event = NULL;
	
	if ((fd = inotify_init())<0)	{
		perror("error:");
		return -1;
	}

	if ((g_ffd = inotify_add_watch(fd, "/tmp/test", IN_ALL_EVENTS))<0) {
		printf("inotify add watch failed\n");
		close(fd);
		return -1;
	}

	atexit(cleanup);
	
	while (1) {
		numread = read(fd, buf, BUF_LEN);
		if (numread < 0) {
			printf("read failed");
			continue;
		}

		for (ptr=buf; ptr<buf+numread; ptr+=sizeof(struct inotify_event)+event->len) {
			event = (struct inotify_event *)ptr;
			display_event(event);
		}
	}

	if (fd)	{
		close(fd);
		fd = 0;
	}
	return 0;
}
