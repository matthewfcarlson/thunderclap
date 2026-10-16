// STATUS: equivalent (tools/equiv.py level 3: 356 inputs, branch coverage 12/12)
// FUN_002b3c70 @ 0x002b3c70
#include "decls/address.h"
struct V3_2b3c70 {
    float x, y, z;
    void FUN_0022d180();
};

struct Tri_2b3c70 {
    short a, b, c;
};

struct Mesh_2b3c70 {
    char pad0[0x10];
    V3_2b3c70 *verts;
};

struct Batch_2b3c70 {
    char pad0[8];
    V3_2b3c70 *p8;
    char pad0c[4];
    int *p10;
    void FUN_0008ef00();
};

struct Sink_2b3c70 {
    char pad0[0x10];
    void *f10;
};

class Gfx {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Batch_2b3c70 *v30(void *sink, int a, int b, int count, int c);
    virtual void v31(Batch_2b3c70 *b);
};

extern Sink_2b3c70 *DAT_00554bb4;
extern unsigned int DAT_0052cbac;
extern Tri_2b3c70 DAT_0052cbb0[];
extern int DAT_004d06dc;

class DebugMesh {
public:
    char pad0[0x48];
    Mesh_2b3c70 *mesh;
    float scale;
    char pad50[4];
    char outline;
    char pad55[3];
    V3_2b3c70 off;
    void F();
};

void DebugMesh::F()
{
    V3_2b3c70 *verts = mesh->verts;
    unsigned int count = DAT_0052cbac;
    if (count == 0)
        return;
    V3_2b3c70 T;
    T.x = off.x;
    T.y = off.y;
    T.z = off.z;
    T.x = T.x * scale;
    T.y = T.y * scale;
    T.z = T.z * scale;
    Batch_2b3c70 *batch = DAT_0052c2a8->v30(DAT_00554bb4->f10, 0, 0x2020, count * 6, 0);
    if (!outline) {
        for (unsigned short i = 0; i < DAT_0052cbac; i++) {
            V3_2b3c70 A = verts[DAT_0052cbb0[i].a];
            V3_2b3c70 B = verts[DAT_0052cbb0[i].b];
            V3_2b3c70 C = verts[DAT_0052cbb0[i].c];
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = C.x;
            batch->p8->y = C.y;
            batch->p8->z = C.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = B.x;
            batch->p8->y = B.y;
            batch->p8->z = B.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = A.x;
            batch->p8->y = A.y;
            batch->p8->z = A.z;
            batch->FUN_0008ef00();
            A.x = T.x + A.x;
            A.y = T.y + A.y;
            A.z = T.z + A.z;
            B.x = T.x + B.x;
            B.y = T.y + B.y;
            B.z = T.z + B.z;
            C.x = T.x + C.x;
            C.y = T.y + C.y;
            C.z = T.z + C.z;
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = A.x;
            batch->p8->y = A.y;
            batch->p8->z = A.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = B.x;
            batch->p8->y = B.y;
            batch->p8->z = B.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = C.x;
            batch->p8->y = C.y;
            batch->p8->z = C.z;
            batch->FUN_0008ef00();
        }
    } else {
        for (unsigned short i = 0; i < DAT_0052cbac; i++) {
            struct Frame {
                V3_2b3c70 B;
                V3_2b3c70 C;
                V3_2b3c70 A;
                V3_2b3c70 D[3];
            } f;
            f.A = verts[DAT_0052cbb0[i].a];
            f.B = verts[DAT_0052cbb0[i].b];
            f.C = verts[DAT_0052cbb0[i].c];
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.C.x;
            batch->p8->y = f.C.y;
            batch->p8->z = f.C.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.B.x;
            batch->p8->y = f.B.y;
            batch->p8->z = f.B.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.A.x;
            batch->p8->y = f.A.y;
            batch->p8->z = f.A.z;
            batch->FUN_0008ef00();
            f.D[0].x = f.A.x - off.x;
            f.D[0].y = f.A.y - off.y;
            f.D[0].z = f.A.z - off.z;
            f.D[1].x = f.B.x - off.x;
            f.D[1].y = f.B.y - off.y;
            f.D[1].z = f.B.z - off.z;
            f.D[2].x = f.C.x - off.x;
            f.D[2].y = f.C.y - off.y;
            f.D[2].z = f.C.z - off.z;
            f.D[0].FUN_0022d180();
            f.D[1].FUN_0022d180();
            f.D[2].FUN_0022d180();
            f.D[0].x = f.D[0].x * scale;
            f.D[0].y = f.D[0].y * scale;
            f.D[0].z = f.D[0].z * scale;
            f.D[1].x = f.D[1].x * scale;
            f.D[1].y = f.D[1].y * scale;
            f.D[1].z = f.D[1].z * scale;
            f.D[2].x = f.D[2].x * scale;
            f.D[2].y = f.D[2].y * scale;
            f.D[2].z = f.D[2].z * scale;
            f.A.x = f.D[0].x + f.A.x;
            f.A.y = f.D[0].y + f.A.y;
            f.A.z = f.D[0].z + f.A.z;
            f.B.x = f.D[1].x + f.B.x;
            f.B.y = f.D[1].y + f.B.y;
            f.B.z = f.D[1].z + f.B.z;
            f.C.x = f.D[2].x + f.C.x;
            f.C.y = f.D[2].y + f.C.y;
            f.C.z = f.D[2].z + f.C.z;
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.A.x;
            batch->p8->y = f.A.y;
            batch->p8->z = f.A.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.B.x;
            batch->p8->y = f.B.y;
            batch->p8->z = f.B.z;
            batch->FUN_0008ef00();
            *batch->p10 = DAT_004d06dc;
            batch->p8->x = f.C.x;
            batch->p8->y = f.C.y;
            batch->p8->z = f.C.z;
            batch->FUN_0008ef00();
        }
    }
    DAT_0052c2a8->v31(batch);
}
