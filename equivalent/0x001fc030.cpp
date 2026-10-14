// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// CTriggerVolume::vfunc_8 @ 0x001fc030
struct Vec_1fc030 { float x,y,z; };
// equiv-conv: FUN_00224d70 ecx stack stack
void FUN_00224d70(Vec_1fc030* self, float angle, Vec_1fc030* output);
struct CTriggerVolume {
 char pad[0xb0]; Vec_1fc030 minimum; Vec_1fc030 maximum; float angle;
 void FUN_001fbec0(Vec_1fc030* out);
 bool vfunc_8(float x,float y,float z);
};
bool CTriggerVolume::vfunc_8(float x,float y,float z) {
 Vec_1fc030 p; p.x=x; p.y=y; p.z=z;
 double px;
 if (angle != 0.0f) {
  Vec_1fc030* center = (Vec_1fc030*)&x;
  FUN_001fbec0(center);
  p.x -= x; p.y -= y; p.z -= z;
  FUN_00224d70(&p, -angle, &p);
  px = (double)x + p.x;
  p.y = y + p.y;
  p.z = z + p.z;
 } else px=p.x;
 return px >= minimum.x && px <= maximum.x && p.y >= minimum.y && p.y <= maximum.y && p.z >= minimum.z && p.z <= maximum.z;
}