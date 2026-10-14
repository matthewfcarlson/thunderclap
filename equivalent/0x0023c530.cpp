// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 12/12)
// fight::Store::vfunc_9 @ 0x0023c530
typedef unsigned long DWORD;
typedef unsigned __int64 Key;
extern DWORD DAT_004e5ba8, DAT_004e5bac, DAT_004e5b20, DAT_004e5b24;
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual bool slot13();
 virtual Key slot14();
 virtual void slot15();
 virtual void slot16(Key);
 virtual void slot17();
};
struct Record { char pad[0x28]; DWORD value; };
struct Collection { void FUN_00236ec0(); void FUN_00237160(Key, DWORD, Object*); };
namespace fight {
struct Store {
 char pad[0x18]; Collection collection;
 void FUN_00233c50(Record*, Object*, DWORD);
 void FUN_002337c0(Record*, Object*, int);
 bool vfunc_9(Record*, Object*, DWORD);
};
bool Store::vfunc_9(Record* record, Object* object, DWORD arg) {
 if (!object->slot13()) return false;
 Key key = object->slot14();
 if ((DWORD)key != DAT_004e5ba8 || (DWORD)(key >> 32) != DAT_004e5bac) return false;
 object->slot16(((Key)DAT_004e5bac << 32) | DAT_004e5ba8);
 FUN_00233c50(record, object, arg);
 collection.FUN_00236ec0();
 if (object->slot13()) {
  key = object->slot14();
  if ((DWORD)key == DAT_004e5b20 && (DWORD)(key >> 32) == DAT_004e5b24)
   collection.FUN_00237160(((Key)DAT_004e5b24 << 32) | DAT_004e5b20, record->value, object);
 }
 FUN_002337c0(record, object, -1);
 object->slot17();
 return true;
}
}
