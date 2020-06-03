#ifndef __IMAGE_LOADING_LIBRARY_H_INCLUDED__
#define __IMAGE_LOADING_LIBRARY_H_INCLUDED__

#define LIB_LODEPNG 0
#define LIB_FREE_IMAGE 1

typedef struct {
	char* data;
	int width;
	int height;
} ILL_IMAGE;

char *illLoadImage(int, char *);

#endif
