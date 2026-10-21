// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 12/12)
// FUN_003577c0 @ 0x003577c0
#include "compat/ptr.h"
struct Vec3_3577c0 {
    float x, y, z;
};

// Is p inside the triangle v1 v2 v3 (all on the plane with normal n)?
// x87: the edges, cz and the two dot products stay in registers (53 bits); cx and cy go through the frame
bool FUN_003577c0(const Vec3_3577c0 *p, const Vec3_3577c0 *v1, const Vec3_3577c0 *v2, const Vec3_3577c0 *v3, const Vec3_3577c0 *n)
{
    struct Frame {
        float cx, cy;
        float spare;
    } fr;
    int outside = 0;

    hulk_freg ex = v2->x - v1->x;
    hulk_freg ey = v2->y - v1->y;
    hulk_freg ez = v2->z - v1->z;
    fr.cx = ey * n->z - ez * n->y;
    fr.cy = ez * n->x - ex * n->z;
    hulk_freg cz = ex * n->y - ey * n->x;
    hulk_freg a = cz * p->z;
    a += fr.cx * p->x;
    a += fr.cy * p->y;
    hulk_freg b = fr.cx * v1->x;
    b += fr.cy * v1->y;
    b += cz * v1->z;
    if (a - b > 0.0f)
        outside = 1;

    hulk_freg fx = v3->x - v2->x;
    hulk_freg fy = v3->y - v2->y;
    hulk_freg fz = v3->z - v2->z;
    fr.cx = fy * n->z - fz * n->y;
    fr.cy = fz * n->x - fx * n->z;
    cz = fx * n->y - fy * n->x;
    a = cz * p->z;
    a += fr.cx * p->x;
    a += fr.cy * p->y;
    b = fr.cy * v2->y;
    b += fr.cx * v2->x;
    b += cz * v2->z;
    if (a - b > 0.0f)
        outside++;
    if (outside == 1)
        return false;

    hulk_freg gx = v1->x - v3->x;
    hulk_freg gy = v1->y - v3->y;
    hulk_freg gz = v1->z - v3->z;
    fr.cx = gy * n->z - gz * n->y;
    fr.cy = gz * n->x - gx * n->z;
    cz = gx * n->y - gy * n->x;
    a = cz * p->z;
    a += fr.cx * p->x;
    a += fr.cy * p->y;
    b = cz * v3->z;
    b += fr.cy * v3->y;
    b += fr.cx * v3->x;
    if (a - b > 0.0f)
        outside++;
    return outside == 0 || outside == 3;
}
