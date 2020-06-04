#ifndef __IMAGE_LOADING_LIBRARY_H_INCLUDED__
#define __IMAGE_LOADING_LIBRARY_H_INCLUDED__

#define LIB_NIL -1
#define LIB_LODEPNG 0
#define LIB_FREE_IMAGE 1

typedef struct {
	char* data;
	int width;
	int height;
	void *orig_ptr;
} ILL_IMAGE;

ILL_IMAGE illLoadImage(int, char *);
void illEnd(ILL_IMAGE);

#endif
