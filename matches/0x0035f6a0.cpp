#include "decls/data/engine/audio.h"
// data: busName = DAT_004292b8, registry = DAT_004e6080, seqName = DAT_00429270

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
class Registry {
  public:
    void FUN_002584d0(Pair*, Pair*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364210();
void __cdecl init() {
    Pair a = FUN_002672f0(DAT_004292b8, 0, 0);
    Pair b = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6080).FUN_002584d0(&b, &a, 8, 4);
    atexit(FUN_00364210);
}