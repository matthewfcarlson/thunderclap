#include "decls/data/platform/xbox/pure3d.h"
// data: gValues_32a190 = DAT_004d4f04
#include "gen/owners.h"

extern "C" void __fastcall D3DDevice_SetRenderState_Simple(int state, int value);
extern int gStateA;
extern int gStateB;
extern int gStateC;
void owners::Obj_32a190::FUN_0032a190(unsigned char enabled, int mode, int value) {
    if (mEnabled != enabled) {
        mEnabled = enabled;
        D3DDevice_SetRenderState_Simple(0x40300, (unsigned char)enabled);
        gStateA = (unsigned char)enabled;
    }
    if (mEnabled != 0) {
        if (mMode != mode) {
            mMode = mode;
            int v = ((int*)&DAT_004d4f04)[mode];
            D3DDevice_SetRenderState_Simple(0x4033c, v);
            gStateB = v;
        }
        if (mEnabled != 0 && mValue != value) {
            mValue = value;
            D3DDevice_SetRenderState_Simple(0x40340, value);
            gStateC = value;
        }
    }
}