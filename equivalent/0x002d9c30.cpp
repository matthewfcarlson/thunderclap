// STATUS: equivalent (tools/equiv.py level 3: 2571 inputs, branch coverage 89/90, incomplete)
// FUN_002d9c30 @ 0x002d9c30
typedef unsigned char png_byte_2d9c30;
typedef unsigned short png_uint_16;
typedef unsigned int png_uint_32;

struct png_row_info_2d9c30 {
    png_uint_32 width;
    png_uint_32 rowbytes;
    png_byte_2d9c30 color_type;
    png_byte_2d9c30 bit_depth;
    png_byte_2d9c30 channels;
    png_byte_2d9c30 pixel_depth;
};

struct png_struct_2d9c30 {
    char pad0[0x150];
    png_uint_16 gamma_shift;           // 0x150
    char pad152[0x160 - 0x152];
    png_byte_2d9c30 *gamma_from_1;            // 0x160
    png_byte_2d9c30 *gamma_to_1;              // 0x164
    char pad168[4];
    png_uint_16 **gamma_16_from_1;     // 0x16c
    png_uint_16 **gamma_16_to_1;       // 0x170
    char pad174[0x219 - 0x174];
    png_byte_2d9c30 rgb_to_gray_red_coeff;    // 0x219
    png_byte_2d9c30 rgb_to_gray_green_coeff;
    png_byte_2d9c30 rgb_to_gray_blue_coeff;
};

int __cdecl FUN_002d9c30(png_struct_2d9c30 *png_ptr, png_row_info_2d9c30 *row_info, png_byte_2d9c30 *row)
{
    png_uint_32 i;
    png_uint_32 row_width = row_info->width;
    int rgb_error = 0;

    if (row_info->color_type & 2) {
        png_byte_2d9c30 rc = png_ptr->rgb_to_gray_red_coeff;
        png_byte_2d9c30 gc = png_ptr->rgb_to_gray_green_coeff;
        png_byte_2d9c30 bc = png_ptr->rgb_to_gray_blue_coeff;

        if (row_info->color_type == 2) {
            if (row_info->bit_depth == 8) {
                if (png_ptr->gamma_from_1 != 0 && png_ptr->gamma_to_1 != 0) {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_byte_2d9c30 red = png_ptr->gamma_to_1[*(sp++)];
                        png_byte_2d9c30 green = png_ptr->gamma_to_1[*(sp++)];
                        png_byte_2d9c30 blue = png_ptr->gamma_to_1[*(sp++)];
                        if (red != green || red != blue) {
                            rgb_error |= 1;
                            *(dp++) = png_ptr->gamma_from_1[(rc * red + gc * green + bc * blue) >> 8];
                        } else {
                            *(dp++) = *(sp - 1);
                        }
                    }
                } else {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_byte_2d9c30 red = *(sp++);
                        png_byte_2d9c30 green = *(sp++);
                        png_byte_2d9c30 blue = *(sp++);
                        if (red != green || red != blue) {
                            rgb_error |= 1;
                            *(dp++) = (png_byte_2d9c30)((rc * red + gc * green + bc * blue) >> 8);
                        } else {
                            *(dp++) = *(sp - 1);
                        }
                    }
                }
            } else {
                if (png_ptr->gamma_16_to_1 != 0 && png_ptr->gamma_16_from_1 != 0) {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_uint_16 red, green, blue, w;
                        red = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        green = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        blue = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        if (red == green && red == blue) {
                            w = red;
                        } else {
                            png_uint_16 red_1 = png_ptr->gamma_16_to_1[(red & 0xff) >> png_ptr->gamma_shift][red >> 8];
                            png_uint_16 green_1 = png_ptr->gamma_16_to_1[(green & 0xff) >> png_ptr->gamma_shift][green >> 8];
                            png_uint_16 blue_1 = png_ptr->gamma_16_to_1[(blue & 0xff) >> png_ptr->gamma_shift][blue >> 8];
                            png_uint_16 gray16 = (png_uint_16)((rc * red_1 + gc * green_1 + bc * blue_1) >> 8);
                            w = png_ptr->gamma_16_from_1[(gray16 & 0xff) >> png_ptr->gamma_shift][gray16 >> 8];
                            rgb_error |= 1;
                        }
                        *(dp++) = (png_byte_2d9c30)((w >> 8) & 0xff);
                        *(dp++) = (png_byte_2d9c30)(w & 0xff);
                    }
                } else {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_uint_16 red, green, blue, gray16;
                        red = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        green = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        blue = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        if (red != green || red != blue)
                            rgb_error |= 1;
                        gray16 = (png_uint_16)((rc * red + gc * green + bc * blue) >> 8);
                        *(dp++) = (png_byte_2d9c30)((gray16 >> 8) & 0xff);
                        *(dp++) = (png_byte_2d9c30)(gray16 & 0xff);
                    }
                }
            }
        }
        if (row_info->color_type == 6) {
            if (row_info->bit_depth == 8) {
                if (png_ptr->gamma_from_1 != 0 && png_ptr->gamma_to_1 != 0) {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_byte_2d9c30 red = png_ptr->gamma_to_1[*(sp++)];
                        png_byte_2d9c30 green = png_ptr->gamma_to_1[*(sp++)];
                        png_byte_2d9c30 blue = png_ptr->gamma_to_1[*(sp++)];
                        if (red != green || red != blue)
                            rgb_error |= 1;
                        *(dp++) = png_ptr->gamma_from_1[(rc * red + gc * green + bc * blue) >> 8];
                        *(dp++) = *(sp++);
                    }
                } else {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_byte_2d9c30 red = *(sp++);
                        png_byte_2d9c30 green = *(sp++);
                        png_byte_2d9c30 blue = *(sp++);
                        if (red != green || red != blue)
                            rgb_error |= 1;
                        *(dp++) = (png_byte_2d9c30)((rc * red + gc * green + bc * blue) >> 8);
                        *(dp++) = *(sp++);
                    }
                }
            } else {
                if (png_ptr->gamma_16_to_1 != 0 && png_ptr->gamma_16_from_1 != 0) {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_uint_16 red, green, blue, w;
                        red = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        green = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        blue = (png_uint_16)(((*(sp)) << 8) | *(sp + 1)); sp += 2;
                        if (red == green && red == blue) {
                            w = red;
                        } else {
                            png_uint_16 red_1 = png_ptr->gamma_16_to_1[(red & 0xff) >> png_ptr->gamma_shift][red >> 8];
                            png_uint_16 green_1 = png_ptr->gamma_16_to_1[(green & 0xff) >> png_ptr->gamma_shift][green >> 8];
                            png_uint_16 blue_1 = png_ptr->gamma_16_to_1[(blue & 0xff) >> png_ptr->gamma_shift][blue >> 8];
                            png_uint_16 gray16 = (png_uint_16)((rc * red_1 + gc * green_1 + bc * blue_1) >> 8);
                            w = png_ptr->gamma_16_from_1[(gray16 & 0xff) >> png_ptr->gamma_shift][gray16 >> 8];
                            rgb_error |= 1;
                        }
                        *(dp++) = (png_byte_2d9c30)((w >> 8) & 0xff);
                        *(dp++) = (png_byte_2d9c30)(w & 0xff);
                        *(dp++) = *(sp++);
                        *(dp++) = *(sp++);
                    }
                } else {
                    png_byte_2d9c30 *sp = row;
                    png_byte_2d9c30 *dp = row;
                    for (i = 0; i < row_width; i++) {
                        png_uint_16 red, green, blue, gray16;
                        red = (png_uint_16)((*(sp) << 8) | *(sp + 1)); sp += 2;
                        green = (png_uint_16)((*(sp) << 8) | *(sp + 1)); sp += 2;
                        blue = (png_uint_16)((*(sp) << 8) | *(sp + 1)); sp += 2;
                        if (red != green || red != blue)
                            rgb_error |= 1;
                        gray16 = (png_uint_16)((rc * red + gc * green + bc * blue) >> 8);
                        *(dp++) = (png_byte_2d9c30)((gray16 >> 8) & 0xff);
                        *(dp++) = (png_byte_2d9c30)(gray16 & 0xff);
                        *(dp++) = *(sp++);
                        *(dp++) = *(sp++);
                    }
                }
            }
        }
        row_info->channels -= (png_byte_2d9c30)2;
        row_info->color_type &= ~2;
        row_info->pixel_depth = (png_byte_2d9c30)(row_info->channels * row_info->bit_depth);
        row_info->rowbytes = ((row_width * (png_uint_32)row_info->pixel_depth) + 7) >> 3;
    }
    return rgb_error;
}
