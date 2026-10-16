// STATUS: equivalent (tools/equiv.py level 3: 2969 inputs, branch coverage 6/6)
// FUN_0032b530 @ 0x0032b530
#include "decls/data/platform/xbox/pure3d.h"

namespace D3D8 {
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(int stage, int value);
}
struct TexSlot {
    unsigned int v0, v4, v8;
    char pad0c[0x54 - 0xc];
    unsigned int v54;
    char pad58[0x80 - 0x58];
};
extern unsigned int DAT_0039db08;
extern TexSlot DAT_0039db10[];
struct StageCache_32b530 {
    void FUN_00329c90(int stage, int value);
    char pad0[0x18];
    int texCoordIndex[4];
    int modes[4];
    char pad38[0xf4 - 0x38];
    int dirty[4];
};
class TextureStage {
  public:
    char pad0[0x14];
    StageCache_32b530* cache;
    char pad18[0x40 - 0x18];
    int mode;
    int arg;
    void Set(int stage, int texCoord, int value);
};
void TextureStage::Set(int stage, int texCoord, int value) {
    if (cache->texCoordIndex[stage] != texCoord) {
        cache->texCoordIndex[stage] = texCoord;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(stage, texCoord);
    }
    if (cache->dirty[stage] != value) {
        cache->dirty[stage] = value;
        DAT_0039db08 |= 0x400;
        DAT_0039db10[stage].v54 = value;
    }
    if (cache->modes[stage] != mode) {
        cache->modes[stage] = mode;
        unsigned int t = ((unsigned int*)&DAT_004d4efc)[mode];
        DAT_0039db08 |= 1u << stage;
        DAT_0039db10[stage].v0 = t;
        DAT_0039db10[stage].v4 = t;
        DAT_0039db10[stage].v8 = t;
    }
    cache->FUN_00329c90(stage, arg);
}
