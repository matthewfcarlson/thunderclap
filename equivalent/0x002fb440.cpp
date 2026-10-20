// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002fb440 @ 0x002fb440
#include "compat/ptr.h"
#include "decls/data/game/global.h"

struct V3_2fb440 { float x, y, z; };
class Ray_2fb440 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual V3_2fb440* GetOrigin();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual V3_2fb440* GetDirection();
    virtual float GetLength();
};
struct Tri_2fb440 {
    char pad0[0x10];
    unsigned short idx[3];
    char pad16[2];
    bool FUN_002fb440(Ray_2fb440* ray, struct Mesh_2fb440* mesh, int flags);
};
struct MeshData_2fb440 {
    char pad0[8];
    V3_2fb440* verts;
    char padc[0x18 - 0xc];
    Tri_2fb440* tris;
};
struct Mesh_2fb440 {
    char pad0[0x44];
    MeshData_2fb440* data;
};
struct Hitter {
    void FUN_00304530(Ray_2fb440* ray, unsigned int index, float t, V3_2fb440* point, V3_2fb440* normal, Mesh_2fb440* mesh, int flags);
};
struct Globals_2fb440 {
    char pad0[0x1b0];
    Hitter hitter;
};
bool FUN_002fae50(V3_2fb440* tri, V3_2fb440* origin, V3_2fb440* dir, float* t);
void FUN_002fa6b0(V3_2fb440* a, V3_2fb440* b, V3_2fb440* c, V3_2fb440* out);

bool Tri_2fb440::FUN_002fb440(Ray_2fb440* ray, Mesh_2fb440* mesh, int flags)
{
    V3_2fb440 tri[3];
    V3_2fb440* verts = mesh->data->verts;
    tri[0] = verts[idx[0]];
    tri[1] = verts[idx[1]];
    tri[2] = verts[idx[2]];
    float t;
    V3_2fb440* dir = ray->GetDirection();
    V3_2fb440* org = ray->GetOrigin();
    bool hit = FUN_002fae50(tri, org, dir, &t);
    if (!(t >= 0.0f))
        return false;
    if (!(ray->GetLength() >= t))
        return false;
    if (!hit)
        return false;
    V3_2fb440 normal;
    V3_2fb440 point;
    FUN_002fa6b0(&tri[0], &tri[1], &tri[2], &normal);
    V3_2fb440* d2 = ray->GetDirection();
    V3_2fb440* o2 = ray->GetOrigin();
    point.x = t * d2->x + o2->x;
    point.y = t * d2->y + o2->y;
    point.z = t * d2->z + o2->z;
    hulk_uintptr index = ((hulk_uintptr)this - (hulk_uintptr)mesh->data->tris) / 0x18;
    (*(Globals_2fb440**)&DAT_00554c14)->hitter.FUN_00304530(ray, index, t, &point, &normal, mesh, flags);
    return hit;
}
