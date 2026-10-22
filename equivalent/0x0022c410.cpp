// STATUS: equivalent (tools/equiv.py level 3: 10208 inputs, branch coverage 8/8)
// FUN_0022c410 @ 0x0022c410
struct Vec3_22c410 {
    float x, y, z;
};

struct Matrix {
    float m[16];

    // Transforms n points (row-vector convention, translation in the last row).
    void FUN_0022c410(int n, const Vec3_22c410* src, Vec3_22c410* dst);
};

void Matrix::FUN_0022c410(int n, const Vec3_22c410* src, Vec3_22c410* dst)
{
    for (int i = 0; i < n; i++) {
        float x = src[i].z * m[8] + src[i].y * m[4] + src[i].x * m[0] + m[12];
        float y = m[5] * src[i].y + src[i].x * m[1] + src[i].z * m[9] + m[13];
        float z = src[i].x * m[2] + m[10] * src[i].z + m[6] * src[i].y + m[14];
        dst[i].x = x;
        dst[i].y = y;
        dst[i].z = z;
    }
}
