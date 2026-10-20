// STATUS: equivalent (tools/equiv.py level 3: 3337 inputs, branch coverage 230/237, incomplete)
// FUN_002da380 @ 0x002da380
typedef unsigned char png_byte;
typedef unsigned short png_uint_16;
typedef unsigned int png_uint_32;
typedef png_byte *png_bytep;
typedef png_uint_16 **png_uint_16pp;

extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct png_color_16 {
    png_byte index;
    png_uint_16 red;
    png_uint_16 green;
    png_uint_16 blue;
    png_uint_16 gray;
};

struct png_row_info {
    png_uint_32 width;
    png_uint_32 rowbytes;
    png_byte color_type;
    png_byte bit_depth;
    png_byte channels;
    png_byte pixel_depth;
};

#define PNG_COLOR_MASK_ALPHA 4
#define PNG_COLOR_TYPE_GRAY 0
#define PNG_COLOR_TYPE_PALETTE 3
#define PNG_COLOR_TYPE_RGB 2
#define PNG_COLOR_TYPE_GRAY_ALPHA 4
#define PNG_COLOR_TYPE_RGB_ALPHA 6

#define png_composite(composite, fg, alpha, bg) \
    { \
        png_uint_16 temp = (png_uint_16)((png_uint_16)(fg) * (png_uint_16)(alpha) + \
                                         (png_uint_16)(bg) * (png_uint_16)(255 - (png_uint_16)(alpha)) + \
                                         (png_uint_16)128); \
        (composite) = (png_byte)((temp + (temp >> 8)) >> 8); \
    }

#define png_composite_16(composite, fg, alpha, bg) \
    { \
        png_uint_32 temp = (png_uint_32)((png_uint_32)(fg) * (png_uint_32)(alpha) + \
                                         (png_uint_32)(bg) * (png_uint_32)(65535L - (png_uint_32)(alpha)) + \
                                         (png_uint_32)32768L); \
        (composite) = (png_uint_16)((temp + (temp >> 16)) >> 16); \
    }

void __cdecl FUN_002da380(png_row_info *row_info, png_bytep row, png_color_16 *trans_values,
                          png_color_16 *background, png_color_16 *background_1, png_bytep gamma_table,
                          png_bytep gamma_from_1, png_bytep gamma_to_1, png_uint_16pp gamma_16,
                          png_uint_16pp gamma_16_from_1, png_uint_16pp gamma_16_to_1, int gamma_shift)
{
    png_bytep sp, dp;
    png_uint_32 i;
    png_uint_32 row_width = row_info->width;
    int shift;

    if (background != 0 &&
        (!(row_info->color_type & PNG_COLOR_MASK_ALPHA) ||
         (row_info->color_type != PNG_COLOR_TYPE_PALETTE && trans_values))) {
        switch (row_info->color_type) {
        case PNG_COLOR_TYPE_GRAY: {
            switch (row_info->bit_depth) {
            case 1: {
                sp = row;
                shift = 7;
                for (i = 0; i < row_width; i++) {
                    if ((png_uint_16)((*sp >> shift) & 0x01) == trans_values->gray) {
                        *sp &= (png_byte)((0x7f7f >> (7 - shift)) & 0xff);
                        *sp |= (png_byte)(background->gray << shift);
                    }
                    if (!shift) {
                        shift = 7;
                        sp++;
                    } else
                        shift--;
                }
                break;
            }
            case 2: {
                if (gamma_table != 0) {
                    sp = row;
                    shift = 6;
                    for (i = 0; i < row_width; i++) {
                        if ((png_uint_16)((*sp >> shift) & 0x03) == trans_values->gray) {
                            *sp &= (png_byte)((0x3f3f >> (6 - shift)) & 0xff);
                            *sp |= (png_byte)(background->gray << shift);
                        } else {
                            png_byte p = (png_byte)((*sp >> shift) & 0x03);
                            png_byte g = (png_byte)((gamma_table[p | (p << 2) | (p << 4) | (p << 6)] >> 6) & 0x03);
                            *sp &= (png_byte)((0x3f3f >> (6 - shift)) & 0xff);
                            *sp |= (png_byte)(g << shift);
                        }
                        if (!shift) {
                            shift = 6;
                            sp++;
                        } else
                            shift -= 2;
                    }
                } else {
                    sp = row;
                    shift = 6;
                    for (i = 0; i < row_width; i++) {
                        if ((png_uint_16)((*sp >> shift) & 0x03) == trans_values->gray) {
                            *sp &= (png_byte)((0x3f3f >> (6 - shift)) & 0xff);
                            *sp |= (png_byte)(background->gray << shift);
                        }
                        if (!shift) {
                            shift = 6;
                            sp++;
                        } else
                            shift -= 2;
                    }
                }
                break;
            }
            case 4: {
                if (gamma_table != 0) {
                    sp = row;
                    shift = 4;
                    for (i = 0; i < row_width; i++) {
                        if ((png_uint_16)((*sp >> shift) & 0x0f) == trans_values->gray) {
                            *sp &= (png_byte)((0xf0f >> (4 - shift)) & 0xff);
                            *sp |= (png_byte)(background->gray << shift);
                        } else {
                            png_byte p = (png_byte)((*sp >> shift) & 0x0f);
                            png_byte g = (png_byte)((gamma_table[p | (p << 4)] >> 4) & 0x0f);
                            *sp &= (png_byte)((0xf0f >> (4 - shift)) & 0xff);
                            *sp |= (png_byte)(g << shift);
                        }
                        if (!shift) {
                            shift = 4;
                            sp++;
                        } else
                            shift -= 4;
                    }
                } else {
                    sp = row;
                    shift = 4;
                    for (i = 0; i < row_width; i++) {
                        if ((png_uint_16)((*sp >> shift) & 0x0f) == trans_values->gray) {
                            *sp &= (png_byte)((0xf0f >> (4 - shift)) & 0xff);
                            *sp |= (png_byte)(background->gray << shift);
                        }
                        if (!shift) {
                            shift = 4;
                            sp++;
                        } else
                            shift -= 4;
                    }
                }
                break;
            }
            case 8: {
                if (gamma_table != 0) {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp++) {
                        if (*sp == trans_values->gray) {
                            *sp = (png_byte)background->gray;
                        } else {
                            *sp = gamma_table[*sp];
                        }
                    }
                } else {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp++) {
                        if (*sp == trans_values->gray) {
                            *sp = (png_byte)background->gray;
                        }
                    }
                }
                break;
            }
            case 16: {
                if (gamma_16 != 0) {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 2) {
                        png_uint_16 v;
                        v = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                        if (v == trans_values->gray) {
                            *sp = (png_byte)((background->gray >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(background->gray & 0xff);
                        } else {
                            v = gamma_16[*(sp + 1) >> gamma_shift][*sp];
                            *sp = (png_byte)((v >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(v & 0xff);
                        }
                    }
                } else {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 2) {
                        png_uint_16 v;
                        v = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                        if (v == trans_values->gray) {
                            *sp = (png_byte)((background->gray >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(background->gray & 0xff);
                        }
                    }
                }
                break;
            }
            }
            break;
        }
        case PNG_COLOR_TYPE_RGB: {
            if (row_info->bit_depth == 8) {
                if (gamma_table != 0) {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 3) {
                        if (*sp == trans_values->red && *(sp + 1) == trans_values->green &&
                            *(sp + 2) == trans_values->blue) {
                            *sp = (png_byte)background->red;
                            *(sp + 1) = (png_byte)background->green;
                            *(sp + 2) = (png_byte)background->blue;
                        } else {
                            *sp = gamma_table[*sp];
                            *(sp + 1) = gamma_table[*(sp + 1)];
                            *(sp + 2) = gamma_table[*(sp + 2)];
                        }
                    }
                } else {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 3) {
                        if (*sp == trans_values->red && *(sp + 1) == trans_values->green &&
                            *(sp + 2) == trans_values->blue) {
                            *sp = (png_byte)background->red;
                            *(sp + 1) = (png_byte)background->green;
                            *(sp + 2) = (png_byte)background->blue;
                        }
                    }
                }
            } else {
                if (gamma_16 != 0) {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 6) {
                        png_uint_16 r = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                        png_uint_16 g = (png_uint_16)(((*(sp + 2)) << 8) + *(sp + 3));
                        png_uint_16 b = (png_uint_16)(((*(sp + 4)) << 8) + *(sp + 5));
                        if (r == trans_values->red && g == trans_values->green && b == trans_values->blue) {
                            *sp = (png_byte)((background->red >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(background->red & 0xff);
                            *(sp + 2) = (png_byte)((background->green >> 8) & 0xff);
                            *(sp + 3) = (png_byte)(background->green & 0xff);
                            *(sp + 4) = (png_byte)((background->blue >> 8) & 0xff);
                            *(sp + 5) = (png_byte)(background->blue & 0xff);
                        } else {
                            png_uint_16 v = gamma_16[*(sp + 1) >> gamma_shift][*sp];
                            *sp = (png_byte)((v >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(v & 0xff);
                            v = gamma_16[*(sp + 3) >> gamma_shift][*(sp + 2)];
                            *(sp + 2) = (png_byte)((v >> 8) & 0xff);
                            *(sp + 3) = (png_byte)(v & 0xff);
                            v = gamma_16[*(sp + 5) >> gamma_shift][*(sp + 4)];
                            *(sp + 4) = (png_byte)((v >> 8) & 0xff);
                            *(sp + 5) = (png_byte)(v & 0xff);
                        }
                    }
                } else {
                    sp = row;
                    for (i = 0; i < row_width; i++, sp += 6) {
                        png_uint_16 r = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                        png_uint_16 g = (png_uint_16)(((*(sp + 2)) << 8) + *(sp + 3));
                        png_uint_16 b = (png_uint_16)(((*(sp + 4)) << 8) + *(sp + 5));
                        if (r == trans_values->red && g == trans_values->green && b == trans_values->blue) {
                            *sp = (png_byte)((background->red >> 8) & 0xff);
                            *(sp + 1) = (png_byte)(background->red & 0xff);
                            *(sp + 2) = (png_byte)((background->green >> 8) & 0xff);
                            *(sp + 3) = (png_byte)(background->green & 0xff);
                            *(sp + 4) = (png_byte)((background->blue >> 8) & 0xff);
                            *(sp + 5) = (png_byte)(background->blue & 0xff);
                        }
                    }
                }
            }
            break;
        }
        case PNG_COLOR_TYPE_GRAY_ALPHA: {
            if (row_info->bit_depth == 8) {
                if (gamma_to_1 != 0 && gamma_from_1 != 0 && gamma_table != 0) {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 2, dp++) {
                        png_uint_16 a = *(sp + 1);
                        if (a == 0xff)
                            *dp = gamma_table[*sp];
                        else if (a == 0)
                            *dp = (png_byte)background->gray;
                        else {
                            png_byte v, w;
                            v = gamma_to_1[*sp];
                            png_composite(w, v, a, background_1->gray);
                            *dp = gamma_from_1[w];
                        }
                    }
                } else {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 2, dp++) {
                        png_byte a = *(sp + 1);
                        if (a == 0xff)
                            *dp = *sp;
                        else if (a == 0)
                            *dp = (png_byte)background->gray;
                        else {
                            png_composite(*dp, *sp, a, background_1->gray);
                        }
                    }
                }
            } else {
                if (gamma_16 != 0 && gamma_16_from_1 != 0 && gamma_16_to_1 != 0) {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 4, dp += 2) {
                        png_uint_16 a = (png_uint_16)(((*(sp + 2)) << 8) + *(sp + 3));
                        if (a == (png_uint_16)0xffff) {
                            png_uint_16 v;
                            v = gamma_16[*(sp + 1) >> gamma_shift][*sp];
                            *dp = (png_byte)((v >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(v & 0xff);
                        } else if (a == 0) {
                            *dp = (png_byte)((background->gray >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(background->gray & 0xff);
                        } else {
                            png_uint_16 g, v, w;
                            g = gamma_16_to_1[*(sp + 1) >> gamma_shift][*sp];
                            png_composite_16(v, g, a, background_1->gray);
                            w = gamma_16_from_1[(v & 0xff) >> gamma_shift][v >> 8];
                            *dp = (png_byte)((w >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(w & 0xff);
                        }
                    }
                } else {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 4, dp += 2) {
                        png_uint_16 a = (png_uint_16)(((*(sp + 2)) << 8) + *(sp + 3));
                        if (a == (png_uint_16)0xffff) {
                            memcpy(dp, sp, 2);
                        } else if (a == 0) {
                            *dp = (png_byte)((background->gray >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(background->gray & 0xff);
                        } else {
                            png_uint_16 g, v;
                            g = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                            png_composite_16(v, g, a, background_1->gray);
                            *dp = (png_byte)((v >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(v & 0xff);
                        }
                    }
                }
            }
            break;
        }
        case PNG_COLOR_TYPE_RGB_ALPHA: {
            if (row_info->bit_depth == 8) {
                if (gamma_to_1 != 0 && gamma_from_1 != 0 && gamma_table != 0) {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 4, dp += 3) {
                        png_byte a = *(sp + 3);
                        if (a == 0xff) {
                            *dp = gamma_table[*sp];
                            *(dp + 1) = gamma_table[*(sp + 1)];
                            *(dp + 2) = gamma_table[*(sp + 2)];
                        } else if (a == 0) {
                            *dp = (png_byte)background->red;
                            *(dp + 1) = (png_byte)background->green;
                            *(dp + 2) = (png_byte)background->blue;
                        } else {
                            png_byte v, w;
                            v = gamma_to_1[*sp];
                            png_composite(w, v, a, background_1->red);
                            *dp = gamma_from_1[w];
                            v = gamma_to_1[*(sp + 1)];
                            png_composite(w, v, a, background_1->green);
                            *(dp + 1) = gamma_from_1[w];
                            v = gamma_to_1[*(sp + 2)];
                            png_composite(w, v, a, background_1->blue);
                            *(dp + 2) = gamma_from_1[w];
                        }
                    }
                } else {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 4, dp += 3) {
                        png_byte a = *(sp + 3);
                        if (a == 0xff) {
                            *dp = *sp;
                            *(dp + 1) = *(sp + 1);
                            *(dp + 2) = *(sp + 2);
                        } else if (a == 0) {
                            *dp = (png_byte)background->red;
                            *(dp + 1) = (png_byte)background->green;
                            *(dp + 2) = (png_byte)background->blue;
                        } else {
                            png_composite(*dp, *sp, a, background->red);
                            png_composite(*(dp + 1), *(sp + 1), a, background->green);
                            png_composite(*(dp + 2), *(sp + 2), a, background->blue);
                        }
                    }
                }
            } else {
                if (gamma_16 != 0 && gamma_16_from_1 != 0 && gamma_16_to_1 != 0) {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 8, dp += 6) {
                        png_uint_16 a = (png_uint_16)(((png_uint_16)(*(sp + 6)) << 8) + (png_uint_16)(*(sp + 7)));
                        if (a == (png_uint_16)0xffff) {
                            png_uint_16 v;
                            v = gamma_16[*(sp + 1) >> gamma_shift][*sp];
                            *dp = (png_byte)((v >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(v & 0xff);
                            v = gamma_16[*(sp + 3) >> gamma_shift][*(sp + 2)];
                            *(dp + 2) = (png_byte)((v >> 8) & 0xff);
                            *(dp + 3) = (png_byte)(v & 0xff);
                            v = gamma_16[*(sp + 5) >> gamma_shift][*(sp + 4)];
                            *(dp + 4) = (png_byte)((v >> 8) & 0xff);
                            *(dp + 5) = (png_byte)(v & 0xff);
                        } else if (a == 0) {
                            *dp = (png_byte)((background->red >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(background->red & 0xff);
                            *(dp + 2) = (png_byte)((background->green >> 8) & 0xff);
                            *(dp + 3) = (png_byte)(background->green & 0xff);
                            *(dp + 4) = (png_byte)((background->blue >> 8) & 0xff);
                            *(dp + 5) = (png_byte)(background->blue & 0xff);
                        } else {
                            png_uint_16 v, w, x;
                            v = gamma_16_to_1[*(sp + 1) >> gamma_shift][*sp];
                            png_composite_16(w, v, a, background->red);
                            x = gamma_16_from_1[((w & 0xff) >> gamma_shift)][w >> 8];
                            *dp = (png_byte)((x >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(x & 0xff);
                            v = gamma_16_to_1[*(sp + 3) >> gamma_shift][*(sp + 2)];
                            png_composite_16(w, v, a, background->green);
                            x = gamma_16_from_1[((w & 0xff) >> gamma_shift)][w >> 8];
                            *(dp + 2) = (png_byte)((x >> 8) & 0xff);
                            *(dp + 3) = (png_byte)(x & 0xff);
                            v = gamma_16_to_1[*(sp + 5) >> gamma_shift][*(sp + 4)];
                            png_composite_16(w, v, a, background->blue);
                            x = gamma_16_from_1[((w & 0xff) >> gamma_shift)][w >> 8];
                            *(dp + 4) = (png_byte)((x >> 8) & 0xff);
                            *(dp + 5) = (png_byte)(x & 0xff);
                        }
                    }
                } else {
                    sp = row;
                    dp = row;
                    for (i = 0; i < row_width; i++, sp += 8, dp += 6) {
                        png_uint_16 a = (png_uint_16)(((png_uint_16)(*(sp + 6)) << 8) + (png_uint_16)(*(sp + 7)));
                        if (a == (png_uint_16)0xffff) {
                            memcpy(dp, sp, 6);
                        } else if (a == 0) {
                            *dp = (png_byte)((background->red >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(background->red & 0xff);
                            *(dp + 2) = (png_byte)((background->green >> 8) & 0xff);
                            *(dp + 3) = (png_byte)(background->green & 0xff);
                            *(dp + 4) = (png_byte)((background->blue >> 8) & 0xff);
                            *(dp + 5) = (png_byte)(background->blue & 0xff);
                        } else {
                            png_uint_16 v;
                            png_uint_16 r = (png_uint_16)(((*sp) << 8) + *(sp + 1));
                            png_uint_16 g = (png_uint_16)(((*(sp + 2)) << 8) + *(sp + 3));
                            png_uint_16 b = (png_uint_16)(((*(sp + 4)) << 8) + *(sp + 5));
                            png_composite_16(v, r, a, background->red);
                            *dp = (png_byte)((v >> 8) & 0xff);
                            *(dp + 1) = (png_byte)(v & 0xff);
                            png_composite_16(v, g, a, background->green);
                            *(dp + 2) = (png_byte)((v >> 8) & 0xff);
                            *(dp + 3) = (png_byte)(v & 0xff);
                            png_composite_16(v, b, a, background->blue);
                            *(dp + 4) = (png_byte)((v >> 8) & 0xff);
                            *(dp + 5) = (png_byte)(v & 0xff);
                        }
                    }
                }
            }
            break;
        }
        }

        if (row_info->color_type & PNG_COLOR_MASK_ALPHA) {
            row_info->color_type &= ~PNG_COLOR_MASK_ALPHA;
            row_info->channels--;
            row_info->pixel_depth = (png_byte)(row_info->channels * row_info->bit_depth);
            row_info->rowbytes = ((row_width * row_info->pixel_depth + 7) >> 3);
        }
    }
}
