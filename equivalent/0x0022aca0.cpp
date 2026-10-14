// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022aca0 @ 0x0022aca0
struct Vector3_22aca0 { float x,y,z; };
struct Random_22aca0 {
 unsigned int seed1,seed2;
 Vector3_22aca0* FUN_0022aca0(Vector3_22aca0* result);
};
Vector3_22aca0* Random_22aca0::FUN_0022aca0(Vector3_22aca0* result) {
 float values[3];
 for(int i=0;i<3;++i) {
  seed1 = (seed1 & 65535u)*36969u + (seed1 >> 16);
  seed2 = (seed2 & 65535u)*18000u + (seed2 >> 16);
  union { unsigned int bits; float value; } convert;
  convert.bits = (((seed1 << 16) + (seed2 & 65535u)) & 0x7fffffu) | 0x3f800000u;
  values[i] = convert.value - 1.0f;
 }
 result->x=values[0];
 result->y=values[1];
 result->z=values[2];
 return result;
}