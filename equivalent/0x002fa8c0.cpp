// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_002fa8c0 @ 0x002fa8c0
extern float DAT_004d2cb4;

struct V3 {
    float x, y, z;
};

union BoolWord {
    char b;
    int w;
};

struct MeshData {
    char pad00[8];
    V3* verts;
    char pad0c[0xc];
    char* tris;
};

struct Mesh {
    char pad00[0x44];
    MeshData* data;
};

struct Hit {
    char pad00[0x38];
    char part38[0xc];
    char part44[0xc];
    float f50;
    float f54;
    char useAlt;
};

struct Tri {
    char pad00[0x10];
    unsigned short i0;
    unsigned short i1;
    unsigned short i2;
    unsigned short flags;
    char pad18[0];
};

struct Tracker {
    void FUN_00304530(Hit* hit, unsigned int index, float f, V3* a, V3* b, Mesh* mesh, int flags);
};
struct Scene {
    char pad00[0x1b0];
    Tracker tracker;
};
extern Scene* DAT_00554c14;

void FUN_002fa6b0(V3* a, V3* b, V3* c, V3* out);
char FUN_00358b10(void* p38, void* p44, float v1, float v0, V3* a0, V3* a1, V3* a2, V3* normal, float* out, V3* l0c, V3* l18, int b1, int b2, int b4);
char FUN_00358700(void* p38, void* p44, float v1, float v0, V3* a0, V3* a1, V3* a2, V3* normal, float* out, V3* l0c, V3* l18, int b1, int b2, int b4);

struct TriRef {
    char pad00[0x10];
    unsigned short i0;
    unsigned short i1;
    unsigned short i2;
    unsigned short flags;
    char pad18[8];
    char FUN_002fa8c0(Hit* hit, Mesh* mesh, int flags);
};

char TriRef::FUN_002fa8c0(Hit* hit, Mesh* mesh, int flags2)
{
    struct Frame {
        float v1;
        float out;
        BoolWord b4;
        BoolWord b2;
        BoolWord b1;
        int flag;
        V3 normal;
        char pad24[8];
        V3* a2;
        V3 l18;
        V3 l0c;
    } f;
    V3* verts = mesh->data->verts;
    V3* a0 = &verts[i0];
    V3* a1 = &verts[i1];
    f.a2 = &verts[i2];
    FUN_002fa6b0(a0, a1, f.a2, &f.normal);
    f.b1.b = (flags & 1) != 0;
    f.b2.b = (flags & 2) == 2;
    f.b4.b = (flags & 4) == 4;
    f.v1 = hit->f54;
    float v0 = hit->f50;
    f.flag = flags2 & 1;
    if (f.flag) {
        f.v1 = DAT_004d2cb4 + f.v1;
        v0 = DAT_004d2cb4 + v0;
    }
    char ok;
    if (hit->useAlt)
        ok = FUN_00358b10(hit->part38, hit->part44, f.v1, v0, a0, a1, f.a2, &f.normal, &f.out, &f.l0c, &f.l18, f.b1.w, f.b2.w, f.b4.w);
    else
        ok = FUN_00358700(hit->part38, hit->part44, f.v1, v0, a0, a1, f.a2, &f.normal, &f.out, &f.l0c, &f.l18, f.b1.w, f.b2.w, f.b4.w);
    if (f.flag)
        f.out = DAT_004d2cb4 + f.out;
    if (ok) {
        unsigned int index = (unsigned int)((char*)this - mesh->data->tris) / 0x18;
        DAT_00554c14->tracker.FUN_00304530(hit, index, f.out, &f.l0c, &f.l18, mesh, flags2);
    }
    return ok;
}
