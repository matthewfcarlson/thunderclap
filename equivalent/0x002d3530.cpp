// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ParticleSphereGenerator::vfunc_5 @ 0x002d3530
struct Curve_2d3530 { void FUN_0028a1c0(float time, float *output); };
float __cdecl FUN_0028b150(Curve_2d3530 *, Curve_2d3530 *, float, float);
struct Key_2d3530 { char pad[8]; Curve_2d3530 *channels[2]; };
namespace pure3d {
struct ParticleSphereGenerator {
    char pad0[16];
    unsigned char mode;
    char pad11[7];
    float blend;
    unsigned int count;
    unsigned int index;
    char pad24[8];
    Key_2d3530 **keys;
    char pad30[8];
    float values[2];
    void vfunc_5(float time);
};
void ParticleSphereGenerator::vfunc_5(float time)
{
    if (!count)
        return;
    Key_2d3530 *first = keys[index];
    if (mode == 1) {
        Key_2d3530 *second = keys[index + 1];
        values[0] = FUN_0028b150(first->channels[0], second->channels[0], blend, time);
        values[1] = FUN_0028b150(first->channels[1], second->channels[1], blend, time);
    } else {
        first->channels[0]->FUN_0028a1c0(time, &values[0]);
        first->channels[1]->FUN_0028a1c0(time, &values[1]);
    }
}
}
