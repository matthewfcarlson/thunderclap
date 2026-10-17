// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::TextureFont::vfunc_9 @ 0x00294e00
#include "decls/data/game/global.h"

namespace pure3d {
struct TextureFont {
    char padding[0x18];
    float height;
    char padding2[4];
    float spacing;
    float vfunc_9(const unsigned short* text);
};
float TextureFont::vfunc_9(const unsigned short* text)
{
    if (!text) return (*(float*)&DAT_003f32e0);
    float result = height;
    float lineStep = spacing + height;
    while (*text) {
        if (*text == 10) result += lineStep;
        ++text;
    }
    return result;
}
}