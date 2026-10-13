// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002c50c0 @ 0x002c50c0
struct Vec3 {
    float x, y, z;
    void FUN_0022d180();
};

struct Matrix {
    float m[16];
};
void __fastcall FUN_0022b980(Matrix *m);

// equiv-conv: FUN_002c50c0 ebx stack stack stack stack stack stack
Matrix *FUN_002c50c0(Matrix *out, float fromX, float fromY, float fromZ,
                     float toX, float toY, float toZ)
{
    Matrix mat;
    FUN_0022b980(&mat);
    Vec3 *dir = (Vec3 *)&mat.m[0];
    Vec3 *up = (Vec3 *)&mat.m[4];
    Vec3 *right = (Vec3 *)&mat.m[8];

    dir->x = toX - fromX;
    dir->y = toY - fromY;
    dir->z = toZ - fromZ;
    mat.m[12] = fromX;
    mat.m[13] = fromY;
    mat.m[14] = fromZ;
    dir->FUN_0022d180();

    float dz0 = dir->z * 0.0f;
    float ady = dir->y < 0.0f ? -dir->y : dir->y;
    if (ady > 0.95f) {
        up->x = dz0 - dir->y;
        up->y = dir->x - dz0;
        up->z = dir->y * 0.0f - dir->x * 0.0f;
        up->FUN_0022d180();
        right->x = up->z * dir->y - up->y * dir->z;
        right->y = up->x * dir->z - up->z * dir->x;
        right->z = up->y * dir->x - up->x * dir->y;
    } else {
        float dy0 = dir->y * 0.0f;
        right->x = dy0 - dir->z;
        right->y = dz0 - dir->x * 0.0f;
        right->z = dir->x - dy0;
        right->FUN_0022d180();
        up->x = right->y * dir->z - right->z * dir->y;
        up->y = right->z * dir->x - right->x * dir->z;
        up->z = right->x * dir->y - right->y * dir->x;
    }
    *out = mat;
    return out;
}
