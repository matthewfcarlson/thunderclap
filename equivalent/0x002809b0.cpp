// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 18/22, incomplete)
// FUN_002809b0 @ 0x002809b0
struct V3_2809b0 {
    float x, y, z;
};

struct Pair_2809b0 {
    unsigned short face;
    unsigned short key;
};

struct Face_2809b0 {
    Pair_2809b0 pairs[3];              // 0x00
    char pad0c[4];
    unsigned short v[3];        // 0x10
    unsigned short bits;        // 0x16
};

struct MeshData_2809b0 {
    char pad0[0x18];
    Face_2809b0 *faces;                // 0x18
};

struct Mesh_2809b0 {
    char pad0[0x40];
    int key;                    // 0x40
    MeshData_2809b0 *data;             // 0x44
    V3_2809b0 *FUN_001af890(V3_2809b0 *out, unsigned int idx);
    V3_2809b0 *FUN_002f37d0(V3_2809b0 *out, Face_2809b0 *f);
};

char __cdecl FUN_00280840(int a, int b, V3_2809b0 *c, V3_2809b0 *d, V3_2809b0 *e);
char __cdecl FUN_0027f540(Face_2809b0 *f, Face_2809b0 **arr, int count);

class Walker_2809b0 {
public:
    void FUN_002809b0(Mesh_2809b0 *mesh, int arg2, int arg3, Face_2809b0 *arg4, Face_2809b0 *node,
                      Face_2809b0 **arr, int *pcount, int max, int skipBits, int skipDot);
};

void Walker_2809b0::FUN_002809b0(Mesh_2809b0 *mesh, int arg2, int arg3, Face_2809b0 *arg4, Face_2809b0 *node,
                          Face_2809b0 **arr, int *pcount, int max, int skipBits, int skipDot)
{
    int n = *pcount;
    if (n >= max)
        return;

    arr[n] = node;
    *pcount = *pcount + 1;
    int nodeBits = (node->bits >> 5) & 0x1f;

    for (int i = 0; i < 3; ++i) {
        unsigned int key = node->pairs[i].key;
        unsigned short face = node->pairs[i].face;
        if (key != (unsigned int)mesh->key || face == 0xffff)
            continue;

        Face_2809b0 *f = &mesh->data->faces[face];
        unsigned short v2 = f->v[1];
        unsigned short v1 = f->v[0];
        V3_2809b0 t[7];
        V3_2809b0 *r1 = mesh->FUN_001af890(&t[0], f->v[2]);
        V3_2809b0 *r2 = mesh->FUN_001af890(&t[1], v2);
        V3_2809b0 *r3 = mesh->FUN_001af890(&t[2], v1);
        if (!FUN_00280840(arg2, arg3, r3, r2, r1))
            continue;

        V3_2809b0 *p = mesh->FUN_002f37d0(&t[3], f);
        V3_2809b0 *q = mesh->FUN_002f37d0(&t[4], arg4);
        float dot1 = p->z * q->z + p->y * q->y + p->x * q->x;
        p = mesh->FUN_002f37d0(&t[5], f);
        q = mesh->FUN_002f37d0(&t[6], node);
        float dot2 = p->z * q->z + p->y * q->y + p->x * q->x;

        if ((char)skipBits == 0) {
            if (((f->bits >> 5) & 0x1f) != nodeBits)
                continue;
        }
        if ((char)skipDot == 0) {
            if (!((double)dot1 > 0.5))
                continue;
            if (!((double)dot2 > 0.5))
                continue;
        }
        if (FUN_0027f540(f, arr, *pcount))
            continue;

        FUN_002809b0(mesh, arg2, arg3, arg4, f, arr, pcount, max, skipBits, skipDot);
    }
}
