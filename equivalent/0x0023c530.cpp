// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 12/12)
// fight::Store::vfunc_9 @ 0x0023c530
#include "decls/data/engine/fight.h"

typedef unsigned long DWORD;
typedef unsigned __int64 Key_23c530;
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual bool slot13();
 virtual Key_23c530 slot14();
 virtual void slot15();
 virtual void slot16(Key_23c530);
 virtual void slot17();
};
struct Record_23c530 { char pad[0x28]; DWORD value; };
struct Collection_23c530 { void FUN_00236ec0(); void FUN_00237160(Key_23c530, DWORD, Object*); };
namespace fight {
struct Store {
 char pad[0x18]; Collection_23c530 collection;
 void FUN_00233c50(Record_23c530*, Object*, DWORD);
 void FUN_002337c0(Record_23c530*, Object*, int);
 bool vfunc_9(Record_23c530*, Object*, DWORD);
};
bool Store::vfunc_9(Record_23c530* record, Object* object, DWORD arg) {
 if (!object->slot13()) return false;
 Key_23c530 key = object->slot14();
 if ((DWORD)key != (*(DWORD*)&DAT_004e5ba8) || (DWORD)(key >> 32) != (*(DWORD*)((char*)&DAT_004e5ba8 + 4))) return false;
 object->slot16(((Key_23c530)(*(DWORD*)((char*)&DAT_004e5ba8 + 4)) << 32) | (*(DWORD*)&DAT_004e5ba8));
 FUN_00233c50(record, object, arg);
 collection.FUN_00236ec0();
 if (object->slot13()) {
  key = object->slot14();
  if ((DWORD)key == (*(DWORD*)&DAT_004e5b20) && (DWORD)(key >> 32) == (*(DWORD*)((char*)&DAT_004e5b20 + 4)))
   collection.FUN_00237160(((Key_23c530)(*(DWORD*)((char*)&DAT_004e5b20 + 4)) << 32) | (*(DWORD*)&DAT_004e5b20), record->value, object);
 }
 FUN_002337c0(record, object, -1);
 object->slot17();
 return true;
}
}
