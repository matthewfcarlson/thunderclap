// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0030b3a0 @ 0x0030b3a0
struct Vec3 { float x,y,z; };
void __stdcall FUN_0030ad10(unsigned int mode, float* result);
struct Provider { void FUN_00310490(unsigned int id, Vec3* out, int flag); };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual float slot6();
 char pad04[8]; unsigned int id; char pad10[8]; Provider* provider; char pad1c[0x7c]; Vec3 axis; char pada4[0x54]; unsigned char mode; char padf9[3]; Vec3 direction; char pad108[0x14]; float result;
 void target();
};
void Object::target() {
 if (mode) {
  FUN_0030ad10(mode, &result);
  Vec3 v;
  provider->FUN_00310490(id, &v, 0);
  if (((v.x*axis.y-v.y*axis.x)*direction.z + (v.z*axis.x-v.x*axis.z)*direction.y + (v.y*axis.z-v.z*axis.y)*direction.x) <= 0.0f) result=-result;
 } else result=slot6();
}