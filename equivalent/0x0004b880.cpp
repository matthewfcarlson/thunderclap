// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 25/26, incomplete)
// CAxisDirectionCondition::vfunc_8 @ 0x0004b880
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000111b0(Vec3 *a, Vec3 *b);
};

struct Obj;

struct Actor {
    char pad000[0x12c];
    Obj *p12c;
    char pad130[0x328 - 0x130];
    Obj *p328;
    char pad32c[0x2064 - 0x32c];
    Vec3 stickA;
    float magA;
    Vec3 stickB;
    Vec3 stickC;
    float FUN_000354c0();
    char FUN_00035550(Vec3 *out);
};

struct Fighter;

Fighter *__fastcall FUN_000592a0(void *owner);
Actor *__fastcall FUN_00059a30(Fighter *f);
extern "C" void __cdecl FUN_00096a90(Obj *o, Vec3 *out);
extern "C" float __cdecl FUN_00224f10(Vec3 *v);
extern "C" float __cdecl FUN_00224fc0(float a, float b);
extern "C" float __cdecl FUN_00018a20(float v);
extern "C" char __cdecl FUN_00018960(float a, float b, float eps);

class CAxisDirectionCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual char vfunc_8(void *owner);
    char pad04[0x8];
    int mode;
    float target;
    float tolerance;
};

char CAxisDirectionCondition::vfunc_8(void *owner)
{
    Fighter *fighter = FUN_000592a0(owner);
    Actor *a = FUN_00059a30(fighter);
    float f;
    switch (mode) {
    case 0:
        f = a->FUN_000354c0();
        if (a->magA <= 0.0f) {
            f = FUN_00224fc0(f, f);
        } else {
            float h = FUN_00224f10(&a->stickA);
            f = FUN_00224fc0(h, f);
        }
        break;
    case 1:
        f = a->FUN_000354c0();
        if (a->p328) {
            Vec3 v1;
            v1.x = 0.0f;
            v1.y = 0.0f;
            v1.z = 0.0f;
            FUN_00096a90(a->p328, &v1);
            Vec3 v2;
            v2.x = 0.0f;
            v2.y = 0.0f;
            v2.z = 0.0f;
            FUN_00096a90(a->p12c, &v2);
            Vec3 t;
            t.x = v1.x - v2.x;
            t.y = 0.0f;
            t.z = v1.z - v2.z;
            f = FUN_00224f10(&t);
        }
        if (a->magA <= 0.0f) {
            f = FUN_00224fc0(f, f);
        } else {
            float h = FUN_00224f10(&a->stickA);
            f = FUN_00224fc0(h, f);
        }
        break;
    case 2: {
        if (a->magA <= 0.0f)
            return 0;
        Vec3 av = a->stickA;
        Vec3 w;
        w.x = 0.0f;
        w.y = 0.0f;
        w.z = 0.0f;
        if (!a->FUN_00035550(&w))
            return 0;
        double d = (double)av.z * w.z + (double)av.x * w.x + (double)w.y * av.y;
        volatile float by = (float)(av.y * d);
        volatile float bz = (float)(av.z * d);
        av.x = (float)(av.x - av.x * d);
        av.y = (float)(av.y - by);
        av.z = (float)(av.z - bz);
        av.FUN_0022d110();
        f = FUN_00018a20(av.y);
        union {
            float f;
            unsigned int u;
        } ab;
        ab.f = av.y;
        ab.u &= 0x7fffffff;
        if (!FUN_00018960(ab.f, 1.0f, 1e-5f)) {
            Vec3 z;
            z.x = 0.0f;
            z.y = 1.0f;
            z.z = 0.0f;
            Vec3 r;
            r.FUN_000111b0(&av, &z);
            double s = (double)r.z * w.z + (double)r.y * w.y + (double)r.x * w.x;
            if (s > 0.0)
                f = -f;
        }
        break;
    }
    case 3: {
        float f0 = a->FUN_000354c0();
        Vec3 *sel = 0;
        double c = (double)a->stickC.x * a->stickC.x + (double)a->stickC.y * a->stickC.y + (double)a->stickC.z * a->stickC.z;
        if (!(c <= 0.0)) {
            sel = &a->stickC;
        } else {
            double b = (double)a->stickB.x * a->stickB.x + (double)a->stickB.y * a->stickB.y + (double)a->stickB.z * a->stickB.z;
            if (!(b <= 0.0))
                sel = &a->stickB;
        }
        if (sel) {
            float h = FUN_00224f10(sel);
            f = FUN_00224fc0(h, f0);
        } else {
            f = FUN_00224fc0(f0, f0);
        }
        break;
    }
    default:
        return 0;
    }
    float r = FUN_00224fc0(f, target);
    union {
        float f;
        unsigned int u;
    } ar;
    ar.f = r;
    ar.u &= 0x7fffffff;
    return tolerance * 0.5f > ar.f;
}
