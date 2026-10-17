// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001d77c0 @ 0x001d77c0
#include "decls/data/game/global.h"

struct Result { char pad[0x50]; char data; };
struct Container { char pad[0x10]; Result *result; };
struct Object { char pad[0xa0]; Container *container; void *FUN_001d77c0(); };
void *Object::FUN_001d77c0() {
    if (!((*(int*)&DAT_004e2618) & 1)) {
        (*(int*)&DAT_004e2618) |= 1;
        (*(int*)&DAT_004e260c) = 0;
        (*(int*)&DAT_004e2610) = 0;
        (*(int*)&DAT_004e2614) = 0;
    }
    if (container && container->result)
        return &container->result->data;
    return ((int*)&DAT_004e260c);
}