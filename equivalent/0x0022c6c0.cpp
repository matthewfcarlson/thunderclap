// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0022c6c0 @ 0x0022c6c0
struct V3_22c6c0 {
    float x, y, z;
    void FUN_0022d180();
};

struct Matrix {
    float m[16];
    void LookAt(const V3_22c6c0* at, const V3_22c6c0* eye, const V3_22c6c0* up);
};

void Matrix::LookAt(const V3_22c6c0* at, const V3_22c6c0* eye, const V3_22c6c0* up)
{
    V3_22c6c0 f;
    f.x = at->x - eye->x;
    f.y = at->y - eye->y;
    f.z = at->z - eye->z;
    f.FUN_0022d180();

    volatile float rx;
    volatile float ry;
    volatile float rz;
    double rxWide = f.z * up->y - f.y * up->z;
    rx = (float)rxWide;
    ry = f.x * up->z - f.z * up->x;
    rz = f.y * up->x - f.x * up->y;

    volatile float ux, uy, uz;
    ux = f.y * rz - ry * f.z;
    uy = f.z * rxWide - f.x * rz;
    uz = f.x * ry - rxWide * f.y;

    m[0] = rx;  m[1] = ux;  m[2] = f.x;  m[3] = 0.0f;
    m[4] = ry;  m[5] = uy;  m[6] = f.y;  m[7] = 0.0f;
    m[8] = rz;  m[9] = uz;  m[10] = f.z; m[11] = 0.0f;
    m[12] = -(rz * eye->z + rx * eye->x + ry * eye->y);
    m[13] = -(uz * eye->z + ux * eye->x + uy * eye->y);
    m[14] = -(f.x * eye->x + f.y * eye->y + f.z * eye->z);
    m[15] = 1.0f;
}
