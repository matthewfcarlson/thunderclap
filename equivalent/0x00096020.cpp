// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00096020 @ 0x00096020
struct Vec { float x,y,z; };
struct Matrix { float m[12]; };
void __cdecl FUN_00096020(Matrix* out, const Vec* a, const Vec* b) {
    float x = b->z*a->y - b->y*a->z;
    float y = b->x*a->z - b->z*a->x;
    float z = b->y*a->x - b->x*a->y;
    volatile float dot = b->z*a->z + b->y*a->y + a->x*b->x;
    volatile float zz = z*z;
    float yy = y*y;
    float xx = x*x;
    volatile float f = (1.0f-dot)/(xx+yy+zz);
    out->m[0] = xx*f+dot;
    float xy = x*y*f;
    out->m[1] = xy+z;
    float xz = x*z*f;
    volatile float xzf=xz;
    out->m[2] = xz-y;
    out->m[4] = xy-z;
    out->m[5] = yy*f+dot;
    float yz = y*z*f;
    volatile float yzf=yz;
    out->m[6] = yz+x;
    out->m[8] = xzf+y;
    out->m[9] = yzf-x;
    out->m[10] = zz*f+dot;
}
