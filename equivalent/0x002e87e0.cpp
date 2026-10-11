// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 18/18)
// FUN_002e87e0 @ 0x002e87e0
struct png_info {
    char pad00[8];
    unsigned int valid;
};

struct png_struct {
    char pad000[0x60];
    unsigned int mode;
    char pad064[0x11e - 0x64];
    unsigned char color_type;
    char pad11f[3];
    unsigned char channels;
    char pad123[0x174 - 0x123];
    unsigned char sig_red;
    unsigned char sig_green;
    unsigned char sig_blue;
    unsigned char sig_gray;
    unsigned char sig_alpha;
};

void __cdecl FUN_002e69a0(png_struct* png_ptr, const char* msg);
void __cdecl FUN_002e69d0(png_struct* png_ptr, const char* msg);
int __cdecl FUN_002e81e0(png_struct* png_ptr, unsigned int skip);
void __cdecl FUN_002e7580(png_struct* png_ptr, unsigned char* buf, unsigned int length);
void __cdecl FUN_002eb4f0(png_struct* png_ptr, png_info* info_ptr, unsigned char* sig_bit);

/* png_handle_sBIT */
void __cdecl FUN_002e87e0(png_struct* png_ptr, png_info* info_ptr, unsigned int length)
{
    unsigned char buf[4];
    unsigned int truelen;

    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before sBIT");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid sBIT after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (png_ptr->mode & 2) {
        FUN_002e69d0(png_ptr, "Out of place sBIT chunk");
    } else if (info_ptr != 0 && (info_ptr->valid & 2)) {
        FUN_002e69d0(png_ptr, "Duplicate sBIT chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    if (png_ptr->color_type == 3)
        truelen = 3;
    else
        truelen = png_ptr->channels;

    if (length != truelen) {
        FUN_002e69d0(png_ptr, "Incorrect sBIT chunk length");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    FUN_002e7580(png_ptr, buf, truelen);
    if (FUN_002e81e0(png_ptr, 0))
        return;

    if (png_ptr->color_type & 2) {
        png_ptr->sig_red = buf[0];
        png_ptr->sig_green = buf[1];
        png_ptr->sig_blue = buf[2];
        png_ptr->sig_alpha = buf[3];
    } else {
        png_ptr->sig_gray = buf[0];
        png_ptr->sig_red = buf[0];
        png_ptr->sig_green = buf[0];
        png_ptr->sig_blue = buf[0];
        png_ptr->sig_alpha = buf[1];
    }
    FUN_002eb4f0(png_ptr, info_ptr, &png_ptr->sig_red);
}
