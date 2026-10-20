// STATUS: equivalent (tools/equiv.py level 3: 226 inputs, branch coverage 10/10)
// FUN_000e19d0 @ 0x000e19d0
#include "compat/ptr.h"
struct Tbl_e19d0 { void* FUN_000df970(int id); };
struct Reg_e19d0 { char pad[4]; Tbl_e19d0* tbl; };
struct Owner_e19d0 { char pad[4]; Reg_e19d0* reg; };
void* __cdecl FUN_0008d6d0(hulk_uintptr size);
struct FEDoFunction {
 virtual void slot0();
 int pad4; int v8, vc;
 Owner_e19d0* owner;
 char v14;
 char pad[0x34 - 0x15];
 void* fn; int count; int* table;
 FEDoFunction(Owner_e19d0* o, int id, int n);
};
FEDoFunction::FEDoFunction(Owner_e19d0* o, int id, int n) {
 v8 = -1;
 vc = -1;
 owner = o;
 v14 = 0;
 count = n;
 table = 0;
 fn = o->reg->tbl->FUN_000df970(id);
 if (fn) {
  if (count > 0) {
   table = (int*)FUN_0008d6d0(count * 4);
   if (!table) return;
  }
  for (int i = 0; i < count; i++) table[i] = 0;
 }
}
