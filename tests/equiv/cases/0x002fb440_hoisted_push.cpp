struct V3 { float x, y, z; };
class Ray {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual V3* GetOrigin();
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
    virtual V3* GetDirection();
    virtual float GetLength();
};
struct Tri {
    char pad0[0x10];
    unsigned short idx[3];
    char pad16[2];
    bool FUN_002fb440(Ray* ray, struct Mesh* mesh, int flags);
};
struct MeshData {
    char pad0[8];
    V3* verts;
    char padc[0x18 - 0xc];
    Tri* tris;
};
struct Mesh {
    char pad0[0x44];
    MeshData* data;
};
struct Hitter {
    void FUN_00304530(Ray* ray, unsigned int index, float t, V3* point, V3* normal, Mesh* mesh, int flags);
};
struct Globals {
    char pad0[0x1b0];
    Hitter hitter;
};
extern Globals* DAT_00554c14;
bool FUN_002fae50(V3* tri, V3* origin, V3* dir, float* t);
void FUN_002fa6b0(V3* a, V3* b, V3* c, V3* out);

bool Tri::FUN_002fb440(Ray* ray, Mesh* mesh, int flags)
{
    V3 tri[3];
    V3* verts = mesh->data->verts;
    tri[0] = verts[idx[0]];
    tri[1] = verts[idx[1]];
    tri[2] = verts[idx[2]];
    float t;
    V3* dir = ray->GetDirection();
    V3* org = ray->GetOrigin();
    bool hit = FUN_002fae50(tri, org, dir, &t);
    if (!(t >= 0.0f))
        return false;
    if (!(ray->GetLength() >= t))
        return false;
    if (!hit)
        return false;
    V3 normal;
    V3 point;
    FUN_002fa6b0(&tri[0], &tri[1], &tri[2], &normal);
    V3* d2 = ray->GetDirection();
    V3* o2 = ray->GetOrigin();
    point.x = t * d2->x + o2->x;
    point.y = t * d2->y + o2->y;
    point.z = t * d2->z + o2->z;
    unsigned int index = ((unsigned int)this - (unsigned int)mesh->data->tris) / 0x18;
    DAT_00554c14->hitter.FUN_00304530(ray, index, t, &point, &normal, mesh, flags);
    return hit;
}
