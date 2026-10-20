// STATUS: equivalent (tools/equiv.py level 3: 3049 inputs, branch coverage 36/38, incomplete)
// FUN_000f3b20 @ 0x000f3b20
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern char DAT_0049f4f0[];
extern char DAT_004a1274[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

namespace pure3d {
class CompositeDrawable {
public:
    virtual void v0();
};
}

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Vec3_f3b20 {
    float x, y, z;
};

union ParamArg_f3b20 {
    class Param *p;
    char raw[4];
};

class Obj_f3b20 {
public:
    void FUN_000e9090(pure3d::CompositeDrawable *d);
    void FUN_000f1bd0(Vec3_f3b20 v);
};

class Sink_f3b20 {
public:
    char pad0[0x154];
    Obj_f3b20 *objA;
    Obj_f3b20 *objB;
    char pad1[0x4970 - 0x15c];
    float values[8];
    void FUN_000e3de0(Obj_f3b20 *o);
};

class Param {
public:
    float FUN_000fad30();
    char *FUN_000fad90();
    void FUN_000fa0a0();
    char FUN_000f9e90();
};

class Args_f3b20 {
public:
    virtual void v0();
    virtual int GetType();
};

class Loader_f3b20 {
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
    virtual Obj_f3b20 *v29(const char *name, int flag);
};

class Inventory_f3b20 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual pure3d::CompositeDrawable *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned __int64 key);
};


class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(int, int, int, int);
        hulk_intptr mC;
        hulk_intptr mD;
    };

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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual char v34(Param *p, Args_f3b20 *a, ParseFunctor *f);
    virtual char v35(Param *p, Loader_f3b20 *c, void *d, Args_f3b20 *a);
    virtual char v36(Param *p, Loader_f3b20 *c, void *d, Args_f3b20 *a);

    void FUN_000f3940(int a, int b, int c, int d);
    void FUN_000f3b20(ParamArg_f3b20 arg, Loader_f3b20 *c, void *d, Args_f3b20 *args);
};

void FEThingsBase::FUN_000f3b20(ParamArg_f3b20 arg, Loader_f3b20 *c, void *d, Args_f3b20 *args)
{
    Param *param = arg.p;
    Sink_f3b20 *sink = (Sink_f3b20 *)FUN_00344e74(d, 0, DAT_0049f4f0, DAT_004a1274, 0);
    int type = args->GetType();
    if (type == 0xcc74e7a7) {
        Param *p = param;
        const char *s = p->FUN_000fad90();
        Inventory_f3b20 *inv = (*(Inventory_f3b20**)&DAT_004dd9cc);
        unsigned __int64 key = FUN_0027b020(s);
        content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster = new (&arg) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
        pure3d::CompositeDrawable *drawable = inv->v3(caster, key);
        if (!drawable)
            return;
        const char *name = p->FUN_000fad90();
        const char *q = name;
        while (*q++)
            ;
        hulk_intptr len = q - (name + 1);
        if (len != 0) {
            sink->objA = c->v29(name, 0);
            if (sink->objA)
                sink->objA->FUN_000e9090(drawable);
            Vec3_f3b20 rot;
            rot.x = 0.0f;
            rot.y = 0.0f;
            rot.z = -1.57079637f;
            sink->objA->FUN_000f1bd0(rot);
        }
        name = p->FUN_000fad90();
        q = name;
        while (*q++)
            ;
        len = q - (name + 1);
        if (len == 0)
            return;
        sink->objB = c->v29(name, 0);
        if (sink->objB)
            sink->objB->FUN_000e9090(drawable);
        Vec3_f3b20 rot2;
        rot2.x = 0.0f;
        rot2.y = 0.0f;
        rot2.z = 1.57079637f;
        sink->objB->FUN_000f1bd0(rot2);
        return;
    }
    if (type == 0x36fbe7be) {
        int i = 0;
        if (!param->FUN_000f9e90())
            return;
        float *p = sink->values;
        do {
            float v = param->FUN_000fad30();
            if (i >= 0 && i < 8)
                *p = v;
            i++;
            p++;
        } while (param->FUN_000f9e90());
        return;
    }
    if (type == 0x65ba5b03) {
        const char *name = param->FUN_000fad90();
        const char *q = name;
        while (*q++)
            ;
        hulk_intptr len = q - (name + 1);
        if (len == 0)
            return;
        sink->FUN_000e3de0(c->v29(name, 0));
        return;
    }
    if (v35(param, c, d, args))
        return;
    if (v36(param, c, d, args))
        return;
    ParseFunctor f;
    f.mObj = this;
    f.mFn = &FEThingsBase::FUN_000f3940;
    f.mC = (hulk_intptr)c;
    f.mD = (hulk_intptr)d;
    if (v34(param, args, &f))
        return;
    param->FUN_000fa0a0();
}
