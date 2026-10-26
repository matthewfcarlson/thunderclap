#include "decls/data/game/unknown.h"
// data: fmt_1f8f40 = DAT_003f3f38

extern void __cdecl FUN_00267760(char*, int, const char*, const char*);
struct Sub_1f8f40 {
    void call(const char*);
};
class Target_1f8f40 {
    char pad[8];

  public:
    void run(const char*);
};
void Target_1f8f40::run(const char* arg) {
    ((Sub_1f8f40*)((char*)this + 8))->call(arg);
    FUN_00267760((char*)this + 0x41c, 0x20, DAT_003f3f38, arg);
}