extern "C" double fabs(double);

struct png_struct {
    char pad0[0x60];
    unsigned int mode;
    char pad64[0x154 - 0x64];
    float gamma;
};

struct png_info {
    char pad0[8];
    unsigned int valid;
    char pad0c[0x80 - 0x0c];
    float whiteX, whiteY;
    float redX, redY;
    float greenX, greenY;
    float blueX, blueY;
};

extern char DAT_004d9a30[];

void __cdecl FUN_002e69a0(png_struct *png_ptr, const char *msg);
void __cdecl FUN_002e69d0(png_struct *png_ptr, const char *msg);
int __cdecl FUN_002e81e0(png_struct *png_ptr, unsigned int skip);
void __cdecl FUN_002e7580(png_struct *png_ptr, unsigned char *buf, unsigned int length);
void __cdecl FUN_002eb540(png_struct *png_ptr, png_info *info_ptr, int intent);
extern int __cdecl _fwprintf(void *stream, const char *format, ...);

// libpng png_handle_sRGB. The first argument's stack slot doubles as the one-byte intent buffer.
void png_handle_sRGB(png_struct *png_ptr_arg, png_info *info_ptr, unsigned int length)
{
    png_struct *png_ptr = png_ptr_arg;
    unsigned char *intentBuf = (unsigned char *)&png_ptr_arg;
    int intent;
    unsigned int mode = png_ptr->mode;

    if (!(mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before sRGB");
    } else if (mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid sRGB after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (mode & 2) {
        FUN_002e69d0(png_ptr, "Out of place sRGB chunk");
    } else if (info_ptr != 0 && (info_ptr->valid & 0x800)) {
        FUN_002e69d0(png_ptr, "Duplicate sRGB chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (length != 1) {
        FUN_002e69d0(png_ptr, "Incorrect sRGB chunk length");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    FUN_002e7580(png_ptr, intentBuf, 1);
    if (FUN_002e81e0(png_ptr, 0)) {
        return;
    }
    intent = *intentBuf;
    if (intent >= 4) {
        FUN_002e69d0(png_ptr, "Unknown sRGB intent");
        return;
    }

    if (info_ptr->valid & 1) {
        int igamma = (int)(png_ptr->gamma * 100000.0f + 0.5);
        if (igamma != 45000) {
            FUN_002e69d0(png_ptr, "Ignoring incorrect gAMA value when sRGB is also present");
            _fwprintf(DAT_004d9a30, "gamma=%f\n", (double)png_ptr->gamma);
        }
    }

    if (info_ptr->valid & 4) {
        if (fabs(info_ptr->whiteX - 0.3127f) > 0.001 ||
            fabs(info_ptr->whiteY - 0.329f) > 0.001 ||
            fabs(info_ptr->redX - 0.64f) > 0.001 ||
            fabs(info_ptr->redY - 0.33f) > 0.001 ||
            fabs(info_ptr->greenX - 0.3f) > 0.001 ||
            fabs(info_ptr->greenY - 0.6f) > 0.001 ||
            fabs(info_ptr->blueX - 0.15f) > 0.001 ||
            fabs(info_ptr->blueY - 0.06f) > 0.001) {
            FUN_002e69d0(png_ptr, "Ignoring incorrect cHRM value when sRGB is also present");
        }
    }

    FUN_002eb540(png_ptr, info_ptr, intent);
}
