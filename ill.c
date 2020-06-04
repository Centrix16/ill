#include <stdio.h>
#include <stdlib.h>
#include <lodepng.h>
#include <FreeImage.h>
#include "ill.h"

ILL_IMAGE data_image;
static char lib = LIB_LODEPNG;

ILL_IMAGE illLoadImage(int lib_type, char *image_name) {
	FIBITMAP *image = NULL;
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	unsigned char *image = 0;
	unsigned int err = 0, w = 0, h = 0;

	switch(lib_type) {
		case LIB_LODEPNG:
			err = lodepng_decode32_file(&data_image.data, &data_image.width, &data_image.height, image_name);	
			if (err)
				data_image.data = NULL;
			lib = LIB_LODEPNG;
		break;

		case LIB_FREE_IMAGE:
			fif = FreeImage_GetFileType(image_name, 0);
			image = FreeImage_Load(fif, image_name, 0);

			data_image.data = (char *)FreeImage_GetBits(image);
			data_image.width = FreeImage_GetWidth(image);
			data_image.height = FreeImage_GetHeight(image);

			lib = LIB_FREE_IMAGE;
		break;

		default:
			data_image.data = NULL;
			data_image.width = 0;
			data_image.height = 0;

			lib = LIB_NIL;
		break;
	}
	return data_image;
}

void illEnd(ILL_IMAGE *img) {
	switch (lib) {	
		case LIB_LODEPNG:
			free(img);
			break;			
		case LIB_FREE_IMAGE:
			FreeImage_Unload(img);
			break;	
	}
} 
