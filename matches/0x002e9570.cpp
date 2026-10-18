// FUN_002e9570 @ 0x002e9570
struct png_info_2e9570 {
    char pad0[8];
    unsigned int valid;
};

struct png_struct_2e9570 {
    char pad0[0x60];
    unsigned int mode;
    unsigned int flags;
    char pad1[0x110 - 0x68];
    unsigned short num_palette;
    char pad2[0x1ec - 0x112];
    unsigned short *hist;
};

void FUN_002e69a0(png_struct_2e9570 *png, const char *msg);
void FUN_002e69d0(png_struct_2e9570 *png, const char *msg);
int FUN_002e81e0(png_struct_2e9570 *png, unsigned int skip);
unsigned short *FUN_002e6c00(png_struct_2e9570 *png, unsigned int size);
void FUN_002e7580(png_struct_2e9570 *png, unsigned char *buf, unsigned int length);
unsigned short FUN_002e7560(unsigned char *buf);
void FUN_002eb220(png_struct_2e9570 *png, png_info_2e9570 *info, unsigned short *hist);

void FUN_002e9570(png_struct_2e9570 *png, png_info_2e9570 *info, int length)
{
    unsigned char buf[2];
    int num;
    int i;

    if (!(png->mode & 1)) {
        FUN_002e69a0(png, "Missing IHDR before hIST");
    } else if (png->mode & 4) {
        FUN_002e69d0(png, "Invalid hIST after IDAT");
        FUN_002e81e0(png, length);
        return;
    } else if (!(png->mode & 2)) {
        FUN_002e69d0(png, "Missing PLTE before hIST");
        FUN_002e81e0(png, length);
        return;
    } else if (info != 0 && (info->valid & 0x40)) {
        FUN_002e69d0(png, "Duplicate hIST chunk");
        FUN_002e81e0(png, length);
        return;
    }

    if (length != png->num_palette * 2) {
        FUN_002e69d0(png, "Incorrect hIST chunk length");
        FUN_002e81e0(png, length);
        return;
    }

    num = length / 2;
    unsigned short *hist = FUN_002e6c00(png, num * 2);
    png->hist = hist;
    png->flags |= 0x4000;
    for (i = 0; i < num; i++) {
        FUN_002e7580(png, buf, 2);
        png->hist[i] = FUN_002e7560(buf);
    }
    if (FUN_002e81e0(png, 0) == 0)
        FUN_002eb220(png, info, png->hist);
}
