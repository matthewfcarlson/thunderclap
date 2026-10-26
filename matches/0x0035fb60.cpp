#include "decls/data/engine/audio.h"

extern "C" struct Pairs {
    int a;
    int b;
};
extern Pairs __cdecl FUN_002672f0(const char* s, int a, int b);
void __cdecl FUN_0035fb60() {
    Pairs r = FUN_002672f0("Template", 0, 0);
    (*(int*)&DAT_004e6320) = r.a;
    (*(int*)&DAT_004e6324) = r.b;
}
