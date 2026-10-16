// STATUS: equivalent (tools/equiv.py level 3: 648 inputs, branch coverage 11/12, incomplete)
// FUN_001f18b0 @ 0x001f18b0
#include "decls/data/game/unknown.h"

struct Item_1f18b0 {
    Item_1f18b0* FUN_001f06c0(const char* name, void* data, unsigned a, unsigned b, unsigned c);
};
struct Manager_1f18b0 {
    void FUN_001ef260(Item_1f18b0* item);
};
extern unsigned DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned cookie);
extern void* __cdecl FUN_0008d710(unsigned size, unsigned tag);
void __stdcall FUN_001f18b0(const char* name, void* data, unsigned a, unsigned b, unsigned c) {
    unsigned cookie = DAT_004d9968;
    if (name && data) {
        Manager_1f18b0* manager = (*(Manager_1f18b0**)&DAT_004e3710);
        if (manager) {
            char buffer[64] = {0};
            unsigned i = 0;
            do { buffer[i] = name[i]; } while (name[i++]);
            Item_1f18b0* item = (Item_1f18b0*)FUN_0008d710(40, 6);
            if (item) item = item->FUN_001f06c0(name, data, a, b, c);
            manager->FUN_001ef260(item);
        }
    }
    __security_check_cookie(cookie);
}
