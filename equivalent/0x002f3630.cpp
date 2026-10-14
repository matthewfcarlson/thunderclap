// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002f3630 @ 0x002f3630
// equiv-map: ??0MeshBase@@QAE@XZ = 0x003060a0

class Ref_2f3630 {
public:
    virtual void vfunc_0();
};

class MeshBase {
public:
    MeshBase() throw();
    virtual void vfunc_0();
    char pad04[0x34];
};

namespace physics {
class CollisionMesh : public MeshBase {
public:
    int f38, f3c, f40;
    Ref_2f3630* ref;               // 0x44
    int f48;
    int block4c[16];        // 0x4c
    int block8c[16];        // 0x8c
    char flagCC;            // 0xcc
    char padcd[3];
    int fD0;
    CollisionMesh(const CollisionMesh& other) throw();
    virtual void vfunc_0();
};
}

physics::CollisionMesh::CollisionMesh(const CollisionMesh& other) throw()
{
    f38 = other.f38;
    f3c = other.f3c;
    f40 = other.f40;
    ref = other.ref;
    f48 = other.f48;
    flagCC = other.flagCC;
    for (int i = 0; i < 16; i++)
        block4c[i] = other.block4c[i];
    for (int i = 0; i < 16; i++)
        block8c[i] = other.block8c[i];
    fD0 = other.fD0;
    if (ref)
        ref->vfunc_0();
}
