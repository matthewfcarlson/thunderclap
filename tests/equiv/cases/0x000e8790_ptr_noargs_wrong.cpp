extern float (__cdecl *DAT_004de948)();

class Elem {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(float x);
    virtual float v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual char v22();
};

struct ElemList {
    char pad0[0x24];
    Elem **begin;
    Elem **end;
};

struct Holder {
    char pad0[0x48];
    ElemList *list;
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float x, int y);
    char pad4[0x44];
    ElemList *list;
    void FUN_002998d0(int x);
};

struct Target {
    char pad0[0x38];
    int state;
    float f3c;
    char pad40[4];
    float f44;
    float f48;
    char pad4c[5];
    char flag51;
};

class FEPoseAnimation {
public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2();
    char pad4[0x4];
    char pad8[4];
    Owner *owner;
    Target *target;
    char pad14[0x58 - 0x14];
    int reverse;
    char done;
};

void FEPoseAnimation::vfunc_2()
{
    if (done)
        return;
    Target *t = target;
    done = 1;
    if (!t)
        return;
    if (t->state != 2)
        return;
    if (!owner)
        return;
    owner->v6(DAT_004de948() * ((reverse == 0) ? 1 : -1) * 1000.0f, 1);
    owner->FUN_002998d0(0);
    ElemList *l = owner->list;
    if ((char)(l->end - l->begin) == 0)
        return;
    Elem *e = *l->begin;
    if (!e)
        return;
    if (reverse == 0) {
        if (!e->v22()) {
            if (!(target->f44 > -1.0f))
                return;
            float lim = target->f44;
            if (!(e->v13() >= lim))
                return;
        }
        Target *a = target;
        if (a->flag51) {
            if (a->f48 > -1.0f)
                e->v12(a->f48);
            else
                e->v12(a->f3c);
            e->v6(0, 1);
            return;
        }
        a->state = 1;
        a = target;
        if (!(a->f48 > -1.0f))
            return;
        e->v12(a->f48);
        e->v6(0, 1);
        return;
    }
    if (e->v13() <= 0.0f) {
    } else {
        if (!(target->f44 > -1.0f))
            return;
        float lim = target->f44;
        if (!(e->v13() <= lim))
            return;
    }
    Target *a = target;
    if (a->flag51) {
        if (a->f48 > -1.0f)
            e->v12(a->f48);
        else
            e->v12(a->f3c);
        e->v6(0, 1);
        return;
    }
    a->state = 1;
}
