// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ParticleSphereGenerator::vfunc_5 @ 0x002d3530
struct Curve { void FUN_0028a1c0(float time, float *output); };
float __cdecl FUN_0028b150(Curve *, Curve *, float, float);
struct Key { char pad[8]; Curve *channels[2]; };
namespace pure3d {
struct ParticleSphereGenerator {
    char pad0[16];
    unsigned char mode;
    char pad11[7];
    float blend;
    unsigned int count;
    unsigned int index;
    char pad24[8];
    Key **keys;
    char pad30[8];
    float values[2];
    void vfunc_5(float time);
};
void ParticleSphereGenerator::vfunc_5(float time)
{
    if (!count)
        return;
    Key *first = keys[index];
    if (mode == 1) {
        Key *second = keys[index + 1];
        values[0] = FUN_0028b150(first->channels[0], second->channels[0], blend, time);
        values[1] = FUN_0028b150(first->channels[1], second->channels[1], blend, time);
    } else {
        first->channels[0]->FUN_0028a1c0(time, &values[0]);
        first->channels[1]->FUN_0028a1c0(time, &values[1]);
    }
}
}
