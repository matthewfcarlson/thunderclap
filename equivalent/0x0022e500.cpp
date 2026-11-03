// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 11/11)
// FUN_0022e500 @ 0x0022e500
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"

struct Vec3_22e500 {
    float x, y, z;
};

struct Vec4_22e500 {
    float x, y, z, w;
};

struct Matrix4_22e500 {
    Vec4_22e500 row[4];
};


struct Curve_22e500 {
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
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004c9fa8)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 1:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004c9fe8)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 2:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca028)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 3:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca068)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 4:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca0a8)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 5:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca0e8)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 6:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca128)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 7:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca168)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    case 8:
        ((owners::Matrix_22cc10 *)this)->FUN_0022cc10((const owners::Matrix_22cc10 *)(const Matrix4_22e500 *)(((Matrix4_22e500*)&DAT_004ca1a8)), (const owners::Matrix_22cc10 *)(Matrix4_22e500 *)(&g));
        break;
    }
}
