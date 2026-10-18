extern "C" double sin(double);
extern "C" double cos(double);
extern "C" double tan(double);
extern "C" double sqrt(double);

struct Mat {
    float m[16];
    void FUN_0022b980();
    void FUN_0022ba70(float angle);
};

struct Vec3 {
    float x, y, z;
    void FUN_0022d180();
    void FUN_0022d260(Mat *m);
};

union FloatBits {
    float f;
    unsigned int u;
};

float __cdecl FUN_00018a20(float x);

class Rig {
public:
    char pad00[0x60];
    Vec3 center;
    char pad6c[0x84 - 0x6c];
    Vec3 u84;
    Vec3 o90;
    Vec3 c9c;
    Vec3 ea8;
    float ang;
    float rad;
    void FUN_00083e60(Vec3 U, Vec3 V, Vec3 P);
};

void Rig::FUN_00083e60(Vec3 U, Vec3 V, Vec3 P)
{
    double dd = V.z * U.z + V.y * U.y + V.x * U.x;
    volatile float dm = (float)dd;
    FloatBits t;
    t.f = (float)(dd - 1.0f);
    t.u &= 0x7fffffff;
    if (t.f <= 1e-05f) {
        rad = 0.0f;
        ang = 0.0f;
        u84 = U;
        return;
    }
    t.f = (float)(dd + 1.0f);
    t.u &= 0x7fffffff;
    float dxr = P.x - center.x;
    if (t.f <= 1e-05f) {
        V.x = dxr;
        V.y = P.y - center.y;
        ang = 3.1415927f;
        V.z = P.z - center.z;
        rad = (float)(sqrt(V.z * V.z + V.y * V.y + V.x * V.x) * 0.5f);
        V.FUN_0022d180();
        c9c = center;
        ea8 = P;
        float r = rad;
        P.x = V.x * r;
        P.y = V.y * r;
        double rz = r * V.z;
        o90.z = (float)(rz + center.z);
        o90.x = P.x + center.x;
        o90.y = P.y + center.y;
        u84 = U;
        return;
    }
    Vec3 D;
    D.x = dxr;
    D.y = P.y - center.y;
    double dz80 = P.z - center.z;
    D.z = (float)dz80;
    float len0 = (float)sqrt(dz80 * D.z + D.y * D.y + D.x * D.x);
    double a80 = FUN_00018a20(-dm);
    ang = (float)a80;
    t.f = (float)(a80 - 1.57079637f);
    t.u &= 0x7fffffff;
    if (t.f <= 1e-05f) {
        D.FUN_0022d180();
        double ang2 = FUN_00018a20(D.z * V.z + D.y * V.y + D.x * V.x);
        volatile float S = (float)(sin(ang2) * len0);
        double C = cos(ang2) * len0;
        double M = (S < C) ? (double)S : C;
        double R80 = tan(ang * 0.5f) * M;
        rad = (float)R80;
        double sx = U.x * S;
        double sy = U.y * S;
        volatile float sz = U.z * S;
        P.x = sx + center.x;
        P.y = sy + center.y;
        P.z = sz + center.z;
        volatile float wx = U.x * R80;
        volatile float wy = U.y * R80;
        double wz = R80 * U.z;
        c9c.x = P.x - wx;
        c9c.y = P.y - wy;
        c9c.z = (float)(P.z - wz);
        float r2 = rad;
        volatile float vx = V.x * r2;
        volatile float vy = V.y * r2;
        double vz = r2 * V.z;
        P.z = vz + P.z;
        ea8.z = P.z;
        ea8.x = vx + P.x;
        ea8.y = vy + P.y;
    } else {
        rad = (float)(tan(a80 * 0.5f) * len0);
        c9c = center;
        double vx = V.x * len0;
        volatile float vy = V.y * len0;
        volatile float vz = V.z * len0;
        P.z = vz + P.z;
        ea8.z = P.z;
        ea8.x = vx + P.x;
        ea8.y = vy + P.y;
    }
    int sign = 1;
    if (U.z * V.x - V.z * U.x < 0.0f)
        sign = -1;
    Mat M;
    M.FUN_0022b980();
    M.FUN_0022ba70(sign * 1.57079637f);
    Vec3 Uc = U;
    Uc.FUN_0022d260(&M);
    Uc.FUN_0022d180();
    float r3 = rad;
    volatile float ux = Uc.x * r3;
    volatile float uy = Uc.y * r3;
    double uz = r3 * Uc.z;
    V.z = uz + c9c.z;
    o90.z = V.z;
    o90.x = ux + c9c.x;
    o90.y = uy + c9c.y;
    u84 = U;
}
