struct Vec_2f36c0 {
    float x, y, z;
    void FUN_0022d210(const void*);
};
struct Triangle_2f36c0 {
    char data[24];
    void FUN_002fb190(Vec_2f36c0*, void*, unsigned int);
};
struct MeshData_2f36c0 {
    char pad[24];
    Triangle_2f36c0* triangles;
};
struct Query_2f36c0 {
    char pad[8];
    unsigned short* begin;
    unsigned short* end;
    void FUN_002f91e0();
    void FUN_002fa1f0(Vec_2f36c0*, void*);
};
struct Reset_2f36c0 {
    void FUN_003037e0();
};
struct Context {
    char pad[0x1b0];
    Reset_2f36c0 reset;
};
extern Context* DAT_00554c14;
extern unsigned short* DAT_0055543c;
extern unsigned short* DAT_00555440;
namespace physics {
struct CollisionMesh {
    virtual void v0();
    char pad[0x40];
    MeshData_2f36c0* mesh;
    char pad2[0x44];
    char transform[0x40];
    unsigned char transformed;
    bool vfunc_17(const Vec_2f36c0*, unsigned int);
};
} // namespace physics
bool physics::CollisionMesh::vfunc_17(const Vec_2f36c0* input, unsigned int flags) {
    if (flags & 0x10)
        DAT_00554c14->reset.FUN_003037e0();
    Vec_2f36c0 point = *input;
    if (transformed)
        point.FUN_0022d210(transform);
    Query_2f36c0 q;
    q.FUN_002f91e0();
    Vec_2f36c0 bounds[2];
    bounds[0] = point;
    bounds[1] = point;
    bounds[0].y = -1.0e12f;
    *DAT_0055543c = 0;
    q.begin = DAT_00555440;
    q.end = DAT_00555440;
    q.FUN_002fa1f0(bounds, this);
    for (unsigned short* p = q.begin; p != q.end; ++p)
        mesh->triangles[*p].FUN_002fb190(&point, this, flags);
    return true;
}