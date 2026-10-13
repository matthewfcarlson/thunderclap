// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ParticlePlaneGenerator::vfunc_5 @ 0x002d3410
struct Curve { void FUN_0028a1c0(float time, float* output); };
float __cdecl FUN_0028b150(Curve*, Curve*, float, float);
struct Key { char pad[8]; Curve* channels[5]; };
namespace pure3d {
struct ParticlePlaneGenerator {
 char pad0[16];
 unsigned char mode;
 char pad11[7];
 float blend;
 unsigned int count;
 unsigned int index;
 char pad24[8];
 Key** keys;
 char pad30[8];
 float values[5];
 void vfunc_5(float time);
};
void ParticlePlaneGenerator::vfunc_5(float time) {
 if (!count) return;
 Key* first = keys[index];
 if (mode == 1) {
  Key* second = keys[index + 1];
  values[0] = FUN_0028b150(first->channels[0], second->channels[0], blend, time);
  values[1] = FUN_0028b150(first->channels[1], second->channels[1], blend, time);
  values[2] = FUN_0028b150(first->channels[2], second->channels[2], blend, time);
  values[3] = FUN_0028b150(first->channels[3], second->channels[3], blend, time);
  values[4] = FUN_0028b150(first->channels[4], second->channels[4], blend, time);
 } else {
  first->channels[0]->FUN_0028a1c0(time, &values[0]);
  first->channels[1]->FUN_0028a1c0(time, &values[1]);
  first->channels[2]->FUN_0028a1c0(time, &values[2]);
  first->channels[3]->FUN_0028a1c0(time, &values[3]);
  first->channels[4]->FUN_0028a1c0(time, &values[4]);
 }
}
}