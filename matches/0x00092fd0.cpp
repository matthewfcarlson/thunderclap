#include "gen/owners.h"
extern char gA, gB;
struct Inner {
};
struct Result {
    char pad[16];
    Inner inner;
};
extern "C" Result* __cdecl Make(void*, int, void*, void*, int);
struct Owner {
    void* items[734];
    void Run(int, void*, void*);
};
void Owner::Run(int index, void* x, void* y) {
    if (index >= 0x2ca && index <= 0x2dd) {
        Result* r = Make(items[index], 0, &gA, &gB, 0);
        if (r) {
            ((owners::Target_27b040 *)&(r->inner))->FUN_0027b040((hulk_uintptr)x);
            ((owners::TextOwner_92120 *)r)->FUN_00092120((const char *)y);
        }
    }
}