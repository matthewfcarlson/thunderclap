#include "decls/data/game/global.h"
// data: gCurrentVsync = DAT_004c4680, gFlag_1b86f0 = DAT_004c4684, gRenderer = DAT_004dd6e8

struct Renderer_1b86f0 {
    void Setup(int* out, const char* name);
    unsigned char GetBool(const char* name, int a, int b);
    void Finish();
};
struct Ctl_1b86f0 {
    void Apply(unsigned char v);
};
extern "C" void __stdcall FUN_001b86f0(Ctl_1b86f0* ctl) {
    (*(Renderer_1b86f0**)&DAT_004dd6e8)->Setup(((int*)&DAT_004c4684), "Rendering");
    unsigned char value = (*(Renderer_1b86f0**)&DAT_004dd6e8)->GetBool("Lock to VSync", 0x60, 1);
    if (value != DAT_004c4680) {
        DAT_004c4680 = value;
        ctl->Apply(value);
    }
    (*(Renderer_1b86f0**)&DAT_004dd6e8)->Finish();
}
