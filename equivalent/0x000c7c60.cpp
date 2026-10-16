// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_000c7c60 @ 0x000c7c60
#include "decls/address.h"
struct Value_c7c60 { unsigned int low, high; bool FUN_0027af90(const void* other); void FUN_0027af50(); };
void __cdecl FUN_00096e50(Value_c7c60* result, const void* input);
struct Lookup_c7c60 { int FUN_00024280(unsigned int low, unsigned int high); };
struct Checker_c7c60 { bool FUN_001dd7b0(Value_c7c60* value); };
struct World { char pad[12]; Checker_c7c60* checker; char pad2[16]; Lookup_c7c60* lookup; };
struct Slot_c7c60 { unsigned int key; char padding[36]; char value[24]; };
struct Owner_c7c60 { char padding[0x258]; Slot_c7c60 slots[128]; int FUN_000c7c60(unsigned int key, const void* input); };
int Owner_c7c60::FUN_000c7c60(unsigned int key, const void* input) {
 Value_c7c60 value;
 FUN_00096e50(&value, input);
 if (DAT_004dd700->lookup->FUN_00024280(value.low, value.high) || DAT_004dd700->checker->FUN_001dd7b0(&value)) {
  for (int i=0;i<128;++i) {
   if (slots[i].key == key && value.FUN_0027af90(slots[i].value)) {
    value.FUN_0027af50();
    return i;
   }
  }
 }
 value.FUN_0027af50();
 return -1;
}