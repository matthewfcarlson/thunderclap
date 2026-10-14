// STATUS: equivalent (tools/equiv.py level 3: 552 inputs, branch coverage 4/4)
// FUN_002c4360 @ 0x002c4360
struct V3 { float x, y, z; };

struct VBuf_2c4360 {
    char pad0[8];
    V3 *pos;
    char padc[4];
    unsigned int *color;
    void FUN_0008ef00();
};

struct Gfx_2c4360 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual VBuf_2c4360 *v30(void *tex, int prim, int fmt, int count, int z);
    virtual void v31(VBuf_2c4360 *vb);
};
extern Gfx_2c4360 *DAT_0052c2a8;

struct Frame_2c4360 {
    V3 P;                            // S+0x10
    V3 Q;                            // S+0x1c
};

#define EMIT(X, Y, Z) { float x_ = (X); float y_ = (Y); float z_ = (Z); V3 *pp_ = vb->pos; pp_->x = x_; pp_->y = y_; pp_->z = z_; unsigned int *cp_ = vb->color; *cp_ = color; vb->FUN_0008ef00(); }
#define EMITP() { float x_ = f.P.x; float y_ = f.P.y; float z_ = f.P.z; V3 *pp_ = vb->pos; pp_->x = x_; pp_->z = z_; pp_->y = y_; unsigned int *cp_ = vb->color; *cp_ = color; vb->FUN_0008ef00(); }

void __cdecl FUN_002c4360(V3 *a, V3 *b, void *tex, unsigned int color, char wire2)
{
    Frame_2c4360 f;
    f.Q = *a;
    f.P = *a;
    VBuf_2c4360 *vb = DAT_0052c2a8->v30(tex, 2, 0x2020, wire2 ? 0x24 : 0x18, 0);

    f.P.x = b->x;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.Q.z = b->z;
    f.P.z = b->z;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.Q.y = b->y;
    f.P.y = b->y;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.P.z = a->z;
    EMIT(f.Q.x, f.Q.y, a->z);
    EMITP();

    f.Q.y = a->y;
    f.Q.z = a->z;
    f.P.z = b->z;
    f.P.x = a->x;
    f.P.y = a->y;
    EMIT(a->x, a->y, a->z);
    EMITP();

    f.Q.x = b->x;
    f.P.x = b->x;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.Q.y = b->y;
    f.P.y = b->y;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.P.x = a->x;
    EMIT(a->x, f.Q.y, f.Q.z);
    EMITP();

    f.Q.y = a->y;
    f.Q.z = a->z;
    f.P.y = b->y;
    f.P.x = a->x;
    f.P.z = a->z;
    EMIT(a->x, a->y, a->z);
    EMITP();

    f.Q.x = b->x;
    f.P.x = b->x;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.Q.z = b->z;
    f.P.z = b->z;
    EMIT(f.Q.x, f.Q.y, f.Q.z);
    EMITP();

    f.P.x = a->x;
    EMIT(a->x, f.Q.y, f.Q.z);
    EMITP();

    if (wire2) {
        f.Q.z = a->z;
        f.P.z = a->z;
        f.P.x = b->x;
        f.P.y = b->y;
        EMIT(a->x, a->y, a->z);
        EMITP();

        float ox = f.P.x, oy = f.P.y, oz = f.P.z;
        f.Q.z = oz;
        f.P.y = a->y;
        f.P.x = b->x;
        f.P.z = b->z;
        EMIT(ox, oy, oz);
        EMITP();

        ox = f.P.x; oy = f.P.y; oz = f.P.z;
        f.Q.z = oz;
        f.P.x = a->x;
        f.P.y = b->y;
        f.P.z = b->z;
        EMIT(ox, oy, oz);
        EMITP();

        ox = f.P.x; oy = f.P.y; oz = f.P.z;
        f.Q.z = oz;
        f.P.z = a->z;
        f.P.x = a->x;
        f.P.y = a->y;
        EMIT(ox, oy, oz);
        EMITP();

        ox = f.P.x; oy = f.P.y; oz = f.P.z;
        f.Q.z = oz;
        f.P.y = a->y;
        f.P.x = b->x;
        f.P.z = b->z;
        EMIT(ox, oy, oz);
        EMITP();

        f.P.y = b->y;
        f.P.z = b->z;
        f.Q.z = a->z;
        f.P.x = a->x;
        EMIT(b->x, b->y, a->z);
        EMITP();
    }
    DAT_0052c2a8->v31(vb);
}
