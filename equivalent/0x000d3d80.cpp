// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 18/18)
// FUN_000d3d80 @ 0x000d3d80
void *__cdecl FUN_0008d690(unsigned int size);

extern unsigned long long DAT_004ddf30;
extern unsigned long long DAT_004ddf50;
extern unsigned long long DAT_004ddf58;

class Typed {
public:
    virtual void v0();
    virtual unsigned long long GetTypeId();
};

class Arg_d3d80 {
public:
    int FUN_000fad90();
};

class Owner_d3d80 {
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
    virtual void vfunc_23(void *obj, int v);
    char pad04[0xa64 - 4];
    unsigned char dirty;
};

class ObjA_d3d80 {
public:
    ObjA_d3d80 *FUN_000d7af0(int a, int b);
    char FUN_000d7890(Arg_d3d80 *arg, void *p2, Owner_d3d80 *owner);
};
class ObjB_d3d80 {
public:
    ObjB_d3d80 *FUN_000d82d0(int a, void *p1);
    char FUN_000dc230(Arg_d3d80 *arg, void *p2, Owner_d3d80 *owner);
};
class ObjC_d3d80 {
public:
    ObjC_d3d80 *FUN_000dc590(int a);
    char FUN_000dd350(Arg_d3d80 *arg, void *p2, Owner_d3d80 *owner);
};

char __cdecl FUN_000d3d80(void *p1, void *p2, Owner_d3d80 *owner, Arg_d3d80 *arg, Typed *typed)
{
    if (typed->GetTypeId() == DAT_004ddf30) {
        int a = arg->FUN_000fad90();
        int b = arg->FUN_000fad90();
        ObjA_d3d80 *mem = (ObjA_d3d80 *)FUN_0008d690(0x158);
        ObjA_d3d80 *obj = 0;
        if (mem)
            obj = mem->FUN_000d7af0(a, b);
        owner->vfunc_23(obj, a);
        return obj->FUN_000d7890(arg, p2, owner);
    }
    if (typed->GetTypeId() == DAT_004ddf50) {
        int a = arg->FUN_000fad90();
        ObjB_d3d80 *mem = (ObjB_d3d80 *)FUN_0008d690(0x458);
        ObjB_d3d80 *obj = 0;
        if (mem)
            obj = mem->FUN_000d82d0(a, p1);
        owner->vfunc_23(obj, a);
        owner->dirty = 1;
        return obj->FUN_000dc230(arg, p2, owner);
    }
    if (typed->GetTypeId() == DAT_004ddf58) {
        int a = arg->FUN_000fad90();
        ObjC_d3d80 *mem = (ObjC_d3d80 *)FUN_0008d690(0x180);
        ObjC_d3d80 *obj = 0;
        if (mem)
            obj = mem->FUN_000dc590(a);
        owner->vfunc_23(obj, a);
        owner->dirty = 1;
        return obj->FUN_000dd350(arg, p2, owner);
    }
    return 0;
}
