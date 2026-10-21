// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_00096020 @ 0x00096020
#include "compat/ptr.h"
struct Vec_96020 { float x,y,z; };
struct Matrix { float m[12]; };
void __cdecl FUN_00096020(Matrix* out, const Vec_96020* a, const Vec_96020* b) {
    hulk_freg x = b->z*a->y - b->y*a->z;
    hulk_freg y = b->x*a->z - b->z*a->x;
    hulk_freg z = b->y*a->x - b->x*a->y;
    volatile float dot = b->z*a->z + b->y*a->y + a->x*b->x;
    volatile float zz = z*z;
    hulk_freg yy = y*y;
    hulk_freg xx = x*x;
    volatile float f = (1.0f-dot)/(xx+yy+zz);
    out->m[0] = xx*f+dot;
    double xyp = x*y;
    hulk_freg xy = xyp*f;
    out->m[1] = xy+z;
    double xzp = x*z;
    hulk_freg xz = xzp*f;
    volatile float xzf=xz;
    out->m[2] = xz-y;
    out->m[4] = xy-z;
    out->m[5] = yy*f+dot;
    double yzp = y*z;
    hulk_freg yz = yzp*f;
    volatile float yzf=yz;
    out->m[6] = yz+x;
    out->m[8] = xzf+y;
    out->m[9] = yzf-x;
    out->m[10] = zz*f+dot;
}
