// FUN_000a2f90 @ 0x000a2f90
extern "C" double sqrt(double);
struct V3_a2f90 {
    float x, y, z;
};

float __cdecl FUN_000a0450(V3_a2f90 *v);
float __cdecl FUN_000a02a0(float a);

class CChaseCamera_a2f90 {
public:
    char pad0[0x1b8];
    float baseX;            // 0x1b8
    char pad1bc[4];
    float baseZ;            // 0x1c0
    char pad1c4[0x350 - 0x1c4];
    int target;             // 0x350
    void FUN_000a2e60(float angle, int arg);
    void FUN_000a2f90(float x, int unused, float z, int arg);
};

void CChaseCamera_a2f90::FUN_000a2f90(float x, int unused, float z, int arg)
{
    if (target == 0)
        return;
    V3_a2f90 d;
    d.y = 0.0f;
    d.x = x - baseX;
    volatile float *dz = &d.z;
    *dz = z - baseZ;
    float len = (float)sqrt(*dz * *dz + d.x * d.x);
    if (len < 0.01f)
        return;
    if (len > 10000.0f)
        return;
    x = FUN_000a02a0(FUN_000a0450(&d) + 180.0f);
    FUN_000a2e60(x, arg);
}
