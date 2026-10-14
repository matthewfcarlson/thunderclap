// STATUS: equivalent (tools/equiv.py level 3: 59 inputs, branch coverage 12/12)
// pure3d::PrimGroupStreamed::vfunc_10 @ 0x002e02e0
struct V3_2e02e0 { float x, y, z; };
struct V4_2e02e0 { float x, y, z, w; };

struct Bounds_2e02e0 {
    V3_2e02e0 lo;
    V3_2e02e0 hi;
    void FUN_000a87f0(V3_2e02e0 *p);
    V4_2e02e0 *FUN_000a8890(V4_2e02e0 *out);
};

struct Xform_2e02e0 {
    char pad0[0x10];
    V3_2e02e0 *offset;
};

struct Mesh_2e02e0 {
    char pad0[0x18];
    V3_2e02e0 *points;
    char pad1c[0x58 - 0x1c];
    Xform_2e02e0 *xform;
};

class PrimGroupStreamed {
public:
    char pad0[0x14];
    Bounds_2e02e0 bounds;
    V4_2e02e0 sphere;
    char pad3c[0x4c - 0x3c];
    unsigned int count;
    char pad50[0x5c - 0x50];
    Mesh_2e02e0 *mesh;
    void FUN_002e02e0();
};

void PrimGroupStreamed::FUN_002e02e0()
{
    V3_2e02e0 *pts = mesh->points;
    Xform_2e02e0 *xf = mesh->xform;
    V4_2e02e0 tmp; // scratch point (x,y,z); FUN_000a8890 then reuses it as its 4-float output
    if (xf && xf->offset) {
        V3_2e02e0 *off = xf->offset;
        bounds.lo.x = off->x + pts->x;
        bounds.lo.y = pts->y + off->y;
        bounds.lo.z = pts->z + off->z;
        bounds.hi.x = off->x + pts->x;
        bounds.hi.y = pts->y + off->y;
        bounds.hi.z = pts->z + off->z;
        for (unsigned int i = 1; i < count; i++) {
            tmp.x = pts[i].x + off->x;
            tmp.y = pts[i].y + off->y;
            tmp.z = off->z + pts[i].z;
            bounds.FUN_000a87f0((V3_2e02e0 *)&tmp);
        }
    } else {
        bounds.lo = *pts;
        bounds.hi = *pts;
        for (unsigned int i = 1; i < count; i++)
            bounds.FUN_000a87f0(&pts[i]);
    }
    sphere = *bounds.FUN_000a8890(&tmp);
}
