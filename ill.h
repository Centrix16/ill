#ifndef __IMAGE_LOADING_LIBRARY_H_INCLUDED__
#define __FILE_LOADING_LIBRARY_H_INCLUDED__

#define LIB_LODEPNG 0
#define LIB_FREE_IMAGE 1

typedef struct ILL_IMAGE {
	char data[BUFSIZ];
	int width;
	int height;
};

char *illLoadImage(int, char *);

#endif