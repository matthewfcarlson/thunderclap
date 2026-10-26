#include "decls/data/game/hulkfight/motion.h"
// data: gDevice = DAT_004e0fb0

extern "C" int __cdecl atexit(void (*f)());
extern void __cdecl FUN_00363f50();
struct Device {
    void Open(const char*, int);
};
void __cdecl FUN_0035e3a0() {
    (*(Device*)&DAT_004e0fb0).Open("sound/rsd", 0);
    atexit(FUN_00363f50);
}
