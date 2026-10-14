// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0031c570 @ 0x0031c570
// Fills a 2D texture-level description from a format descriptor and an optional locked surface.
struct FormatDesc_31c570 {
    int format;
    char pad04[0x10];
    int width;
    int height;
};

struct Surface_31c570 {
    int pitch;
    int bits;
};

struct LevelDesc_31c570 {
    int width;
    int height;
    int bytesPerPixel;
    int depth;
    char pad10[0x38];
    int stride;
    int slicePitch;
    int bits;
};

// equiv-conv: FUN_0031c180 eax
int FUN_0031c180(int format);
void __cdecl FUN_0031c290(int format, LevelDesc_31c570 *out);

void FUN_0031c570(const FormatDesc_31c570 *desc, const Surface_31c570 *surf, LevelDesc_31c570 *out, char flipped)
{
    out->width = desc->width;
    out->height = desc->height;
    out->depth = 1;
    out->bytesPerPixel = FUN_0031c180(desc->format);
    if (surf) {
        int format = desc->format;
        if (flipped && format != 0xc && format != 0xe && format != 0xf) {
            out->bits = (out->height - 1) * surf->pitch + surf->bits;
            out->stride = -surf->pitch;
        } else {
            out->bits = surf->bits;
            out->stride = surf->pitch;
        }
    }
    FUN_0031c290(desc->format, out);
}
