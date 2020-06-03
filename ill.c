#include <stdio.h>
#include <FreeImage.h>
#include "ill.h"

ILL_IMAGE data_image;

ILL_IMAGE illLoadImage(int lib_type, char *image_name) {
	FIBITMAP *image;
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

	switch(lib_type) {
		case LIB_LODEPNG:
			/* code */
			break;
		case LIB_FREE_IMAGE:
			fif = FreeImage_GetFileType(image_name, 0);
			image = FreeImage_Load(fif, image_name, 0);

			data_image.data = (char *)FreeImage_GetBits(image);
			data_image.width = FreeImage_GetWidth(image);
			data_image.height = FreeImage_GetHeight(image);

			FreeImage_Unload(image);

			break;
		default:
			break;
	}
	return data_image;
}
