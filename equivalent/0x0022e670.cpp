// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 11/11)
// FUN_0022e670 @ 0x0022e670
struct Vec4 {
    float x, y, z, w;
};

struct Matrix4 {
    Vec4 row[4];
};

extern Matrix4 DAT_004c9fa8;
extern Matrix4 DAT_004c9fe8;
extern Matrix4 DAT_004ca028;
extern Matrix4 DAT_004ca068;
extern Matrix4 DAT_004ca0a8;
extern Matrix4 DAT_004ca0e8;
extern Matrix4 DAT_004ca128;
extern Matrix4 DAT_004ca168;
extern Matrix4 DAT_004ca1a8;

struct Curve {
    void FUN_0022cc10(const Matrix4 *basis, Matrix4 *geometry);
    void FUN_0022e670(int type, const Vec4 *p0, const Vec4 *p1, const Vec4 *p2, const Vec4 *p3);
};

void Curve::FUN_0022e670(int type, const Vec4 *p0, const Vec4 *p1, const Vec4 *p2, const Vec4 *p3)
{
    Matrix4 g;
    g.row[0] = *p0;
    g.row[1] = *p1;
    g.row[2] = *p2;
    g.row[3] = *p3;
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
