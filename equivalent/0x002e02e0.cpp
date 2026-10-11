// STATUS: equivalent (tools/equiv.py level 3: 59 inputs, branch coverage 12/12)
// pure3d::PrimGroupStreamed::vfunc_10 @ 0x002e02e0
struct V3 { float x, y, z; };
struct V4 { float x, y, z, w; };

struct Bounds {
    V3 lo;
    V3 hi;
    void FUN_000a87f0(V3 *p);
    V4 *FUN_000a8890(V4 *out);
};

struct Xform {
    char pad0[0x10];
    V3 *offset;
};

struct Mesh {
    char pad0[0x18];
    V3 *points;
    char pad1c[0x58 - 0x1c];
    Xform *xform;
};

class PrimGroupStreamed {
public:
    char pad0[0x14];
    Bounds bounds;
    V4 sphere;
    char pad3c[0x4c - 0x3c];
    unsigned int count;
    char pad50[0x5c - 0x50];
    Mesh *mesh;
    void FUN_002e02e0();
};

void PrimGroupStreamed::FUN_002e02e0()
{
    V3 *pts = mesh->points;
    Xform *xf = mesh->xform;
    V4 tmp; // scratch point (x,y,z); FUN_000a8890 then reuses it as its 4-float output
    if (xf && xf->offset) {
        V3 *off = xf->offset;
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
            bounds.FUN_000a87f0((V3 *)&tmp);
        }
    } else {
        bounds.lo = *pts;
        bounds.hi = *pts;
        for (unsigned int i = 1; i < count; i++)
            bounds.FUN_000a87f0(&pts[i]);
    }
    sphere = *bounds.FUN_000a8890(&tmp);
}
