// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0031c600 @ 0x0031c600
// Fills a texture-level description from a format descriptor and an optional locked surface.
struct FormatDesc_31c600 {
    int format;
    char pad04[0xc];
    int width;
    int height;
    int depth;
};

struct Surface_31c600 {
    int pitch;
    int slicePitch;
    int bits;
};

struct LevelDesc_31c600 {
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
void __cdecl FUN_0031c290(int format, LevelDesc_31c600 *out);

void FUN_0031c600(const FormatDesc_31c600 *desc, const Surface_31c600 *surf, LevelDesc_31c600 *out, char flipped)
{
    out->width = desc->width;
    out->height = desc->height;
    out->depth = desc->depth;
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
        out->slicePitch = surf->slicePitch;
    }
    FUN_0031c290(desc->format, out);
}
