#include "gen/pure3d.h"

class Font_295150 {
    char pad[0x20];
};
extern const float zero_295150;

void pure3d::TextureFont::vfunc_13(float x) {
    if (x > 0.0f)
        *(float*)((char*)this + 0x20) = x;
    else
        *(int*)((char*)this + 0x20) = 0;
}
