#include "decls/data/engine/fight.h"
// data: g_arg = DAT_004e5c94

typedef unsigned int u32_23f1d0;
typedef unsigned char u8_23f1d0;
class BreakPointAction {
    char pad[0x20];

  public:
    u32_23f1d0 member;
    u8_23f1d0 vfunc_3(u32_23f1d0 a, u32_23f1d0 b);
};
u8_23f1d0 BreakPointAction::vfunc_3(u32_23f1d0 a, u32_23f1d0 b) {
    if ((*(u32_23f1d0*)&DAT_004e5c90)) {
        typedef void(__cdecl * Fn)(u32_23f1d0, u32_23f1d0);
        ((Fn)(*(u32_23f1d0*)&DAT_004e5c90))(member, (*(u32_23f1d0*)&DAT_004e5c94));
    }
    return 0;
}