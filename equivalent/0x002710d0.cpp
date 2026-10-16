// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_002710d0 @ 0x002710d0
#include "decls/data/engine/unknown.h"

struct Source_2710d0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int status();
};
struct Slot_2710d0 { Source_2710d0 *source; char rest[0x118]; };
struct Result_2710d0 { Result_2710d0 *FUN_002764d0(Source_2710d0 *, int, int, int, int, int, int, int, int); };
struct Work_2710d0 { volatile int first, second; int key; char gap[16]; char buffer[0x100]; char pad[0x20]; };
void __cdecl FUN_002697c0(int, void *, void *, volatile int *, volatile int *);
int __cdecl FUN_0026d850(void *);
int __cdecl FUN_0026d840(void *);
int __cdecl FUN_00270c10(void *);
void __cdecl FUN_00270f10(void *, int);
Result_2710d0 * __cdecl FUN_00275d50(int);
int __cdecl FUN_002710d0(Result_2710d0 **out, int input, int a, int b, int c, int d, int e, int f) {
 Work_2710d0 work;
 work.first = 0;
 work.second = 0;
 FUN_002697c0(input, work.buffer, &work.key, &work.second, &work.first);
 FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
 int index = FUN_00270c10(&work.key);
 Slot_2710d0 *slot = index == -1 ? 0 : &((Slot_2710d0*)&DAT_0052842c)[index];
 if (!slot || !slot->source) {
  if ((*(char*)&DAT_004cdc04)) {
   FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
   FUN_00270f10(&work.key, DAT_0052a120);
   FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
   index = FUN_00270c10(&work.key);
   slot = index >= 0 ? &((Slot_2710d0*)&DAT_0052842c)[index] : 0;
  }
 }
 if (!slot || !slot->source) {
  *out = 0;
  return FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
 }
 int selected = work.second;
 int status = slot->source->status();
 if ((signed char)status < 0) selected = work.first;
 Result_2710d0 *result = FUN_00275d50(0x168);
 if (result) result = result->FUN_002764d0(slot->source, selected, a, b, c, d, e, f, 1);
 *out = result;
 return FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
}