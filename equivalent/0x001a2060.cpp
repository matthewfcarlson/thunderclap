// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001a2060 @ 0x001a2060
extern const float DAT_003f32b8;
struct Angles { float x,y,z; };
struct Obj { char pad[0x44]; float x,y,z; unsigned int FUN_001a2060(const Angles *angles); };
unsigned int Obj::FUN_001a2060(const Angles *angles) {
    x = angles->x * DAT_003f32b8;
    y = angles->y * DAT_003f32b8;
    z = angles->z * DAT_003f32b8;
    union { float f; unsigned int u; } bits;
    bits.f = z;
    return (bits.u & 0xffffff00u) | 1u;
}