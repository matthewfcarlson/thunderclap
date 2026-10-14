// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00098190 @ 0x00098190
extern "C" double cos(double);

struct V3_98190 {
    float x, y, z;
};

struct Mat_98190 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_98190 *axis, float angle);
    void FUN_0022c3b0(const V3_98190 *in, V3_98190 *out);
};

extern float DAT_004dd940;

int __cdecl FUN_00097a30(int a1, float a2, int a3, int a4, int a5, int a6, int a7, V3_98190 *b, int a9, int a10, int a11, int a12);

int FUN_00098190(float a1, int a2, float a3, int a4, int a5, int a6, int a7, V3_98190 *io, int a9, int a10, int a11)
{
    V3_98190 a = *io;
    V3_98190 b = *io;
    int result = FUN_00097a30(a2, a3, a4, a5, a6, a7, 0, &b, a9, a10, a11, 1);
    if (!result)
        return 0;

    float p = a1 * a3;
    float c;
    if (p < 0.0f || p > 3.14159f)
        c = -1.0f;
    else
        c = (float)cos(p);
    float dot = b.z * a.z + b.y * a.y + b.x * a.x;
    if (dot >= c - DAT_004dd940) {
        *io = b;
        return result;
    }
    if (!(DAT_004dd940 - 1.0f >= dot)) {
        V3_98190 cross;
        cross.x = a.z * b.y - b.z * a.y;
        cross.y = b.z * a.x - a.z * b.x;
        cross.z = b.x * a.y - b.y * a.x;
        if (cross.z * cross.z + cross.y * cross.y + cross.x * cross.x > 0.0f) {
            Mat_98190 m;
            m.FUN_0022b980();
            m.FUN_0022baf0(&cross, p);
            m.FUN_0022c3b0(&a, io);
        }
    }
    return result;
}
