// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_0009a290 @ 0x0009a290
inline void* operator new(unsigned int, void* p) throw() { return p; }
void* FUN_00263ea0(unsigned int size);

extern float DAT_003f32e0;
extern float DAT_003f32b8;

struct Matrix {
    char data[0x40];
    Matrix() { FUN_0022b980(); }
    void FUN_0022ba70(float angle);
    void FUN_0022be40(void* v);
    void FUN_0022b980();
};

class __declspec(novtable) Emitter {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    char FUN_000aa450(void* ctx, Matrix* m, void* pos, int a, void* b, int c, int d);
    Emitter* FUN_000ac2c0();
    char body[0x480 - 4];
};

struct Obj1 { void FUN_00085f50(char a); };
struct Obj2 { void FUN_001bf860(char a); };
struct Obj5 { void FUN_000afe80(); };
struct Obj4 { Obj5* FUN_00086330(); };
struct Obj6 { void FUN_000361c0(char a); void FUN_00036140(char a); };
struct Obj3 { int FUN_000d6f50(); void FUN_000d7030(int a); };
struct Owner {
    Obj1* FUN_00086320();
    Obj2* FUN_00086380();
};
struct Flag { char pad[8]; char value; };
struct Ctx20 { char pad[0x124]; Obj6* obj; };

struct Ctx {
    char pad00[4];
    Flag* flag;
    char pad08[0x18];
    Ctx20* p20;
    char pad24[0x18];
    Obj3* p3c;
    char pad40[0x14];
    Obj4* p54;
};

class Spawner {
public:
    char pad00[4];
    unsigned int flags;
    char pad08[4];
    Owner* owner;
    Emitter* slot10;
    Emitter* slot14;
    char pad18[0x68];
    char vec80[0xc];
    float angle;
    int f90;
    int f94;
    int f98;
    int f9c;
    char vecA0[0x14];
    Emitter* emitter;

    void FUN_0009a220();
    void FUN_0009a290(Ctx* ctx);
};

void Spawner::FUN_0009a290(Ctx* ctx)
{
    Matrix m;
    if (angle != DAT_003f32e0)
        m.FUN_0022ba70(angle * DAT_003f32b8);
    m.FUN_0022be40(vec80);
    if (emitter == 0) {
        void* mem = FUN_00263ea0(0x480);
        Emitter* e = 0;
        if (mem)
            e = ((Emitter*)mem)->FUN_000ac2c0();
        emitter = e;
        e->v00();
        emitter->v70();
    }
    Obj6* obj6 = ctx->p20->obj;
    if (emitter->FUN_000aa450(ctx, &m, vecA0, f9c, obj6, f94, f90)) {
        owner->FUN_00086320()->FUN_00085f50(1);
        f98 = ctx->p3c->FUN_000d6f50();
        int bit = f98 & 0x100;
        owner->FUN_00086380()->FUN_001bf860(1);
        ctx->p3c->FUN_000d7030(bit);
        ctx->flag->value = 0;
        ctx->p54->FUN_00086330()->FUN_000afe80();
        if (obj6) {
            obj6->FUN_000361c0(1);
            obj6->FUN_00036140(1);
        }
        Emitter* e = emitter;
        Emitter* old = slot10;
        slot10 = e;
        slot14 = old;
        flags |= 4;
    }
    FUN_0009a220();
}
