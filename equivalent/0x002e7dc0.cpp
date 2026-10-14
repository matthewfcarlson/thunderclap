// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 43/43)
// FUN_002e7dc0 @ 0x002e7dc0
struct png_struct;

struct png_row_info_2e7dc0 {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
};

void FUN_002e69d0(png_struct *png_ptr, const char *message);

static int abs_int(int v)
{
    return v < 0 ? -v : v;
}

void FUN_002e7dc0(png_struct *png_ptr, png_row_info_2e7dc0 *row_info, unsigned char *row,
                  unsigned char *prev_row, int filter)
{
    unsigned int i;
    unsigned int bpp;
    unsigned int rowbytes;
    unsigned char *rp;
    unsigned char *lp;
    unsigned char *pp;
    unsigned char *cp;

    switch (filter) {
    case 0:
        break;
    case 1:
        bpp = (row_info->pixel_depth + 7) >> 3;
        rowbytes = row_info->rowbytes;
        rp = row + bpp;
        lp = row;
        for (i = bpp; i < rowbytes; i++) {
            *rp = (unsigned char)(*rp + *lp);
            rp++;
            lp++;
        }
        break;
    case 2:
        rowbytes = row_info->rowbytes;
        rp = row;
        pp = prev_row;
        for (i = 0; i < rowbytes; i++) {
            *rp = (unsigned char)(*rp + *pp);
            rp++;
            pp++;
        }
        break;
    case 3:
        bpp = (row_info->pixel_depth + 7) >> 3;
        rowbytes = row_info->rowbytes;
        pp = prev_row;
        rp = row;
        lp = row;
        for (i = 0; i < bpp; i++) {
            *rp = (unsigned char)(*rp + (*pp / 2));
            pp++;
            rp++;
        }
        for (i = 0; i < rowbytes - bpp; i++) {
            *rp = (unsigned char)(*rp + ((*pp + *lp) / 2));
            pp++;
            lp++;
            rp++;
        }
        break;
    case 4:
        bpp = (row_info->pixel_depth + 7) >> 3;
        rowbytes = row_info->rowbytes;
        pp = prev_row;
        cp = prev_row;
        lp = row;
        rp = row;
        for (i = 0; i < bpp; i++) {
            *rp = (unsigned char)(*rp + *pp);
            rp++;
            pp++;
        }
        for (i = 0; i < rowbytes - bpp; i++) {
            int a = *lp++;
            int c = *cp++;
            int b = *pp++;
            int p = b - c;
            int pc = a - c;
            int pa = abs_int(p);
            int pb = abs_int(pc);
            pc = abs_int(p + pc);
            if (pa <= pb && pa <= pc)
                p = a;
            else if (pb <= pc)
                p = b;
            else
                p = c;
            *rp = (unsigned char)(*rp + p);
            rp++;
        }
        break;
    default:
        FUN_002e69d0(png_ptr, "Ignoring bad adaptive filter type");
        *row = 0;
        break;
    }
}
