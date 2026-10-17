// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f16e0 @ 0x001f16e0
#include "decls/data/game/unknown.h"

struct Item { int FUN_001f04e0(void*, void*, unsigned, unsigned); };
struct Manager { void FUN_001ef260(int); };
extern "C" void* __cdecl FUN_0008d710(unsigned, unsigned);
void __stdcall FUN_001f16e0(void* a, void* b, unsigned c, unsigned d) {
    if (a && b) {
        Manager* manager = (*(Manager**)&DAT_004e3710);
        if (manager) {
            Item* item = (Item*)FUN_0008d710(0x20, 6);
            if (item)
                manager->FUN_001ef260(item->FUN_001f04e0(a,b,c,d));
            else
                manager->FUN_001ef260(0);
        }
    }
}