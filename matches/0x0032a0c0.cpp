#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"

extern void __fastcall SetRenderState(unsigned int state, unsigned int value);
extern unsigned int g0_32a0c0, g1, g2, g3;
void owners::State_32a0c0::FUN_0032a0c0(unsigned char flag, int a, int b, int c) {
    if (flag != this->flag) {
        this->flag = flag;
        SetRenderState(0x40304, flag);
        g0_32a0c0 = flag;
    }
    if (this->flag) {
        if (a != this->a) {
            this->a = a;
            SetRenderState(0x40350, a);
            g3 = a;
        }
        if (b != this->b) {
            this->b = b;
            unsigned int v = ((unsigned int*)&DAT_004d4ed0)[b];
            SetRenderState(0x40344, v);
            g1 = v;
        }
        if (c != this->c) {
            this->c = c;
            unsigned int v = ((unsigned int*)&DAT_004d4ed0)[c];
            SetRenderState(0x40348, v);
            g2 = v;
        }
    }
}