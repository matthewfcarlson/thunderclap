// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// CTriggerVolume::vfunc_12 @ 0x001fb4f0
struct Vec3 { float x,y,z; };
struct PositionSource { unsigned char FUN_00059a50(Vec3* out); };
struct TriggerObject { char pad[8]; unsigned int field8; unsigned int fieldC; PositionSource* source; };
struct CTriggerVolume {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5();
 virtual void vfunc_6();
 virtual void vfunc_7();
 virtual unsigned char vfunc_8(Vec3 position);
 virtual void vfunc_9();
 virtual unsigned char vfunc_10(unsigned int a, unsigned int b);
 virtual void vfunc_11();
 virtual unsigned char vfunc_12(TriggerObject* object);
 virtual void vfunc_13(TriggerObject* object);
 virtual void vfunc_14(TriggerObject* object);
 virtual void vfunc_15(TriggerObject* object);
 char padding[0xc9];
 unsigned char enabled;
};
unsigned char CTriggerVolume::vfunc_12(TriggerObject* object) {
 Vec3 position;
 if (!object || !enabled || !object->source->FUN_00059a50(&position)) return 0;
 unsigned char inside = vfunc_8(position);
 unsigned char previous = vfunc_10(object->field8, object->fieldC);
 if (inside == 1) {
  if (previous == inside) vfunc_15(object);
  else vfunc_13(object);
 } else if (previous == 1) {
  vfunc_14(object);
 }
 return inside;
}