// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 21/22, incomplete)
// FUN_00306c60 @ 0x00306c60
#include "compat/ptr.h"
void* __cdecl FUN_0008d690(hulk_uintptr size);
struct BasicCopy { BasicCopy* FUN_00306c00(); };
struct CopyB { CopyB* FUN_00306b40(); };
struct CopyC { CopyC* FUN_00306ba0(); };
struct CopyD { CopyD* FUN_0030e700(); };
struct CopyE { CopyE* FUN_00312900(); };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual unsigned int type();
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual void attach(void* copy);
 void* clone();
};
void* Object::clone() {
 void* result = 0;
 void* memory;
 switch (type()) {
 case 1:
  memory = FUN_0008d690(0x44);
  if (memory) result = ((CopyE*)memory)->FUN_00312900();
  break;
 case 2:
  memory = FUN_0008d690(0x8c);
  if (memory) result = ((CopyB*)memory)->FUN_00306b40();
  break;
 case 5:
  memory = FUN_0008d690(0xbc);
  if (memory) result = ((CopyC*)memory)->FUN_00306ba0();
  break;
 case 7:
  memory = FUN_0008d690(0x48);
  if (memory) result = ((BasicCopy*)memory)->FUN_00306c00();
  break;
 case 8:
  memory = FUN_0008d690(0x60);
  if (memory) result = ((CopyD*)memory)->FUN_0030e700();
  break;
 }
 if (result) attach(result);
 return result;
}