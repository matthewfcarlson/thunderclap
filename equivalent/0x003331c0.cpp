// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 12/12)
// pure3d::d3dBumpMapVertexShader::vfunc_14 @ 0x003331c0
#include "decls/data/platform/xbox/pure3d.h"

typedef unsigned int uint;
namespace D3D8 {
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(uint stage, uint value);
}
extern uint DAT_0039db08;
extern uint DAT_0039db10, DAT_0039db14, DAT_0039db18;
extern uint DAT_0039db90, DAT_0039db94, DAT_0039db98;
extern uint DAT_0039dc10, DAT_0039dc14, DAT_0039dc18;
extern uint DAT_0039dc90, DAT_0039dc94, DAT_0039dc98;
extern uint DAT_0039de9c, DAT_0039dea0, DAT_0039dea4;

struct TextureState_3331c0 {
    char pad0[0x18];
    uint coord0;
    uint coord1;
    char pad20[0x28 - 0x20];
    uint blend0;
    uint blend1;
    uint blend2;
    uint blend3;
    void FUN_0032a920(uint a, uint tex1, uint tex0, uint b, uint c);
    void FUN_00329c90(uint stage, uint value);
};

namespace pure3d {
class d3dBumpMapVertexShader {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14(int unused);
    char pad04[0x14 - 4 - 0];
    TextureState_3331c0* state;
    char pad18[0x40 - 0x18];
    uint mode;
    uint value;
    char pad48[0x80 - 0x48];
    uint tex0;
    uint tex1;
};
}

void pure3d::d3dBumpMapVertexShader::vfunc_14(int unused) {
    state->FUN_0032a920(4, tex1, tex0, 0, 0);
    if (state->coord0 != 0) {
        state->coord0 = 0;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(0, 0);
    }
    if (state->coord1 != 1) {
        state->coord1 = 1;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(1, 1);
    }
    if (state->blend0 != mode) {
        state->blend0 = mode;
        uint v = ((uint*)&DAT_004d4efc)[mode];
        DAT_0039db10 = v;
        DAT_0039db14 = v;
        DAT_0039db08 |= 1;
        DAT_0039db18 = v;
    }
    state->FUN_00329c90(0, value);
    if (state->blend1 != 0) {
        state->blend1 = 0;
        uint v = ((uint*)&DAT_004d4efc)[0];
        DAT_0039db90 = v;
        DAT_0039db94 = v;
        DAT_0039db08 |= 2;
        DAT_0039db98 = v;
    }
    state->FUN_00329c90(1, value);
    if (state->blend2 != 1) {
        state->blend2 = 1;
        uint v = ((uint*)&DAT_004d4efc)[1];
        DAT_0039dc10 = v;
        DAT_0039dc14 = v;
        DAT_0039db08 |= 4;
        DAT_0039dc18 = v;
    }
    state->FUN_00329c90(3, value);
    if (state->blend3 != 1) {
        state->blend3 = 1;
        uint v = ((uint*)&DAT_004d4efc)[1];
        DAT_0039dc90 = v;
        DAT_0039dc94 = v;
        DAT_0039db08 |= 8;
        DAT_0039dc98 = v;
    }
    state->FUN_00329c90(3, value);
    DAT_0039dc10 = 3;
    DAT_0039dc14 = 3;
    DAT_0039dc18 = 3;
    DAT_0039dc90 = 3;
    DAT_0039dc94 = 3;
    DAT_0039dc98 = 3;
    DAT_0039de9c = 0;
    DAT_0039dea0 = 0;
    DAT_0039dea4 = 0;
    DAT_0039db90 = 1;
    DAT_0039db94 = 1;
    DAT_0039db98 = 1;
    DAT_0039db08 |= 0xf;
}
