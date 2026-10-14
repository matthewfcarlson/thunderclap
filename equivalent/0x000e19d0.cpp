// STATUS: equivalent (tools/equiv.py level 3: 226 inputs, branch coverage 10/10)
// FUN_000e19d0 @ 0x000e19d0
struct Tbl { void* FUN_000df970(int id); };
struct Reg { char pad[4]; Tbl* tbl; };
struct Owner { char pad[4]; Reg* reg; };
void* __cdecl FUN_0008d6d0(unsigned size);
struct FEDoFunction {
 virtual void slot0();
 int pad4; int v8, vc;
 Owner* owner;
 char v14;
 char pad[0x34 - 0x15];
 void* fn; int count; int* table;
 FEDoFunction(Owner* o, int id, int n);
};
FEDoFunction::FEDoFunction(Owner* o, int id, int n) {
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
