#include "decls/data/game/global.h"
// data: g_mgr = DAT_004e21f8, k_path = DAT_003f3ea0

extern "C" int __cdecl _atexit(void (*)(void));
struct Mgr {
    void Init(const char*, int);
};
extern void __cdecl shutdown(void);
void __cdecl FUN_0035e690() {
    (*(Mgr*)&DAT_004e21f8).Init(DAT_003f3ea0, 0);
    _atexit(shutdown);
}
