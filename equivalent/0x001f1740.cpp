// STATUS: equivalent (tools/equiv.py level 3: 18759 inputs, branch coverage 11/12, incomplete)
// FUN_001f1740 @ 0x001f1740
// cl-flags: /GS
#include "decls/data/game/unknown.h"

struct Item_1f1740 { Item_1f1740* FUN_001f0630(const char*, void*, unsigned, unsigned); };
struct Manager_1f1740 { void FUN_001ef260(Item_1f1740*); };
extern void* __cdecl FUN_0008d710(unsigned, unsigned);
void __stdcall FUN_001f1740(const char* name, void* value, unsigned a, unsigned b) {
 if (name && value) {
 Manager_1f1740* manager = (*(Manager_1f1740**)&DAT_004e3710);
 if (manager) {
 char buffer[64] = {0};
 unsigned i=0;
 do { buffer[i]=name[i]; } while(name[i++]);
 Item_1f1740* p=(Item_1f1740*)FUN_0008d710(32,6);
 if(p) p=p->FUN_001f0630(name,value,a,b);
 manager->FUN_001ef260(p);
 }
 }
}
