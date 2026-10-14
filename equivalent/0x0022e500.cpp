// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 11/11)
// FUN_0022e500 @ 0x0022e500
struct Vec3_22e500 {
    float x, y, z;
};

struct Vec4_22e500 {
    float x, y, z, w;
};

struct Matrix4_22e500 {
    Vec4_22e500 row[4];
};

extern Matrix4_22e500 DAT_004c9fa8;
extern Matrix4_22e500 DAT_004c9fe8;
extern Matrix4_22e500 DAT_004ca028;
extern Matrix4_22e500 DAT_004ca068;
extern Matrix4_22e500 DAT_004ca0a8;
extern Matrix4_22e500 DAT_004ca0e8;
extern Matrix4_22e500 DAT_004ca128;
extern Matrix4_22e500 DAT_004ca168;
extern Matrix4_22e500 DAT_004ca1a8;

struct Curve_22e500 {
    void FUN_0022cc10(const Matrix4_22e500 *basis, Matrix4_22e500 *geometry);
    void FUN_0022e500(int type, const Vec3_22e500 *p0, const Vec3_22e500 *p1, const Vec3_22e500 *p2, const Vec3_22e500 *p3);
};

void Curve_22e500::FUN_0022e500(int type, const Vec3_22e500 *p0, const Vec3_22e500 *p1, const Vec3_22e500 *p2, const Vec3_22e500 *p3)
{
    Matrix4_22e500 g;
    g.row[0].x = p0->x;
    g.row[0].y = p0->y;
    g.row[0].z = p0->z;
    g.row[0].w = 1.0f;
    g.row[1].x = p1->x;
    g.row[1].y = p1->y;
    g.row[1].z = p1->z;
    g.row[1].w = 1.0f;
    g.row[2].x = p2->x;
    g.row[2].y = p2->y;
    g.row[2].z = p2->z;
    g.row[2].w = 1.0f;
    g.row[3].x = p3->x;
    g.row[3].y = p3->y;
    g.row[3].z = p3->z;
    g.row[3].w = 1.0f;
    switch (type) {
    case 0:
        FUN_0022cc10(&DAT_004c9fa8, &g);
        break;
    case 1:
        FUN_0022cc10(&DAT_004c9fe8, &g);
        break;
    case 2:
        FUN_0022cc10(&DAT_004ca028, &g);
        break;
    case 3:
        FUN_0022cc10(&DAT_004ca068, &g);
        break;
    case 4:
        FUN_0022cc10(&DAT_004ca0a8, &g);
        break;
    case 5:
        FUN_0022cc10(&DAT_004ca0e8, &g);
        break;
    case 6:
        FUN_0022cc10(&DAT_004ca128, &g);
        break;
    case 7:
        FUN_0022cc10(&DAT_004ca168, &g);
        break;
    case 8:
        FUN_0022cc10(&DAT_004ca1a8, &g);
        break;
    }
}
