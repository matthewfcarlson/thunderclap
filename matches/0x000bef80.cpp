#include "gen/owners.h"
extern "C" long __cdecl atol(const char*);
struct Arg {
    char* name;
    char* value;
};
struct Obj {
};
struct Handler {
    char pad[4];
    Obj* ptr;
    int Process(int, Arg*);
};
int Handler::Process(int mode, Arg* arg) {
    if (!ptr)
        return -1;
    if (mode != 2)
        return -1;
    if (arg->value)
        ((owners::MenuScreen_bc9f0 *)ptr)->FUN_000bc9f0((hulk_intptr)(arg->name), (int)(atol(arg->value)));
    return 0;
}