// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 19/24, incomplete)
// FUN_002e86a0 @ 0x002e86a0
struct png_struct_2e86a0 {
    char pad[0x60];
    unsigned int mode;
    char pad2[0x154 - 0x64];
    float gamma;
};

struct png_info_2e86a0 {
    char pad[8];
    unsigned int valid;
};

extern int DAT_004d9a30;

void FUN_002e69a0(png_struct_2e86a0* png, const char* msg);
void FUN_002e69d0(png_struct_2e86a0* png, const char* msg);
int FUN_002e81e0(png_struct_2e86a0* png, unsigned int length);
void FUN_002e7580(png_struct_2e86a0* png, unsigned char* buf, unsigned int length);
unsigned int FUN_002e7500(unsigned char* buf);
void FUN_002eb1f0(png_struct_2e86a0* png, png_info_2e86a0* info, double gamma);
int FUN_00347792(void* stream, const char* fmt, ...);

void FUN_002e86a0(png_struct_2e86a0* png, png_info_2e86a0* info, unsigned int length)
{
    unsigned char buf[4];

    if (!(png->mode & 1)) {
        FUN_002e69a0(png, "Missing IHDR before gAMA");
    } else if (png->mode & 4) {
        FUN_002e69d0(png, "Invalid gAMA after IDAT");
        FUN_002e81e0(png, length);
        return;
    } else if (png->mode & 2) {
        FUN_002e69d0(png, "Out of place gAMA chunk");
    } else if (info != 0 && (info->valid & 1) && !(info->valid & 0x800)) {
        FUN_002e69d0(png, "Duplicate gAMA chunk");
        FUN_002e81e0(png, length);
        return;
    }

    if (length != 4) {
        FUN_002e69d0(png, "Incorrect gAMA chunk length");
        FUN_002e81e0(png, length);
        return;
    }

    FUN_002e7580(png, buf, 4);
    if (FUN_002e81e0(png, 0) != 0)
        return;

    unsigned int igamma = FUN_002e7500(buf);
    if (igamma == 0)
        return;

    if ((info->valid & 0x800) && igamma != 45000) {
        FUN_002e69d0(png, "Ignoring incorrect gAMA value when sRGB is also present");
        FUN_00347792(&DAT_004d9a30, "igamma = %lu\n", igamma);
        return;
    }

    float gamma = (float)igamma * 1e-5f;
    png->gamma = gamma;
    FUN_002eb1f0(png, info, gamma);
}
