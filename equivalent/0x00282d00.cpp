// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 16/16)
// pure3d::prop::CMotionTrail::vfunc_6 @ 0x00282d00
struct Vec3 {
    float x, y, z;
};

struct UV {
    float u, v;
};

class VertexBuffer {
public:
    char pad00[8];
    Vec3 *pos;
    char padc[4];
    unsigned int *color;
    UV *uv;
    void FUN_0008ef00();
};

class Device {
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
    virtual VertexBuffer *v30(void *handle, int a, int flags, int size, int b);
    virtual void v31(VertexBuffer *vb);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int v);
    virtual int v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62(int v);
    virtual char v63();
};

struct RingElem {
    char pad00[0x9c];
    float vstep;
};

struct Slice {
    Vec3 pos[6];
    Vec3 aux[6];
    UV uv[6];
    unsigned int color;
    void FUN_00282a10(RingElem *e, int n, float v, int a, int b, int c, int d, int f);
};

struct Handle {
    char pad00[0x10];
    void *handle;
};

extern Device *DAT_0052c2a8;

struct Vec3i {
    int x, y, z;
};

struct UVi {
    int u, v;
};

// One vertex: the original loads each of the buffer's attribute pointers once and copies
// the words as integers.
static inline void Emit(VertexBuffer *vb, const Vec3 *p, unsigned int color, const UV *uv)
{
    Vec3i *dst = (Vec3i *)vb->pos;
    const Vec3i *src = (const Vec3i *)p;
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    *vb->color = color;
    UVi *t = (UVi *)vb->uv;
    t->u = ((const UVi *)uv)->u;
    t->v = ((const UVi *)uv)->v;
    vb->FUN_0008ef00();
}

class CMotionTrail {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[0x40 - 4];
    Handle *shader;
    char pad44[4];
    int segs;
    int p4c;
    int p50;
    int p54;
    char pad58[0x64 - 0x58];
    RingElem *ring;
    int head;
    int count;
    char pad70[0x7c - 0x70];
    int p7c;
    char pad80[4];
    int p84;
};

// Every local sits at the original's frame offset, r0/r1 at the top next to the return
// address: with more than 6 segments the uv loops run past uv[6] and the emit loops read
// past the strips into these slots (diffBA/diffAB are the original's pointer-difference
// temporaries), so the layout is observable.
struct Frame {
    int innerI;
    int j;
    Slice *a;
    Slice *b;
    int slot20;
    float v;
    unsigned int color;
    union {
        char c;
        int i;
    } saved1;
    int saved2;
    int diffBA;
    int diffAB;
    Slice r0;
    Slice r1;
};

void CMotionTrail::vfunc_6()
{
    if (shader == 0) {
        return;
    }
    if (count < 2) {
        return;
    }
    Frame f;
    f.saved1.c = DAT_0052c2a8->v63();
    DAT_0052c2a8->v62(0);
    f.saved2 = DAT_0052c2a8->v55();
    DAT_0052c2a8->v54(0);

    f.a = &f.r0;
    f.b = &f.r1;
    f.a->FUN_00282a10(&ring[(count + head - 1) % 50], segs, 0.0f, p7c, p84, p50, p4c, p54);
    for (int i = 0; i < segs; i++) {
        float t = (float)i / (float)(segs - 1);
        f.r1.uv[i].v = t;
        f.r0.uv[i].v = t;
    }
    VertexBuffer *vb = DAT_0052c2a8->v30(shader->handle, 1, 0x2021, (segs + 1) * (count - 1) * 2, 0);
    f.v = 0.0f;
    for (f.j = count - 1; f.j > 0; f.j--) {
        int idx = (f.j + head - 1) % 50;
        f.v = f.v + ring[idx].vstep;
        f.b->FUN_00282a10(&ring[idx], segs, f.v, p7c, p84, p50, p4c, p54);
        f.color = f.a->color;
        Emit(vb, &f.a->pos[0], f.color, &f.a->uv[0]);
        Emit(vb, &f.b->pos[0], f.b->color, &f.b->uv[0]);
        if (segs > 1) {
            f.diffBA = (char *)f.b - (char *)f.a;
            f.diffAB = (char *)f.a - (char *)f.b;
        }
        for (f.innerI = 1; f.innerI < segs; f.innerI++) {
            Emit(vb, &f.a->pos[f.innerI], f.color, &f.a->uv[f.innerI]);
            Emit(vb, &f.b->pos[f.innerI], f.b->color, &f.b->uv[f.innerI]);
        }
        Emit(vb, &f.b->pos[segs - 1], f.b->color, &f.b->uv[segs - 1]);
        Emit(vb, &f.b->pos[0], f.b->color, &f.b->uv[0]);
        Slice *tmp = f.a;
        f.a = f.b;
        f.b = tmp;
    }
    DAT_0052c2a8->v31(vb);
    DAT_0052c2a8->v62(f.saved1.i);
    DAT_0052c2a8->v54(f.saved2);
}
