// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleDamageTrack::vfunc_12 @ 0x0005a510
void *__cdecl FUN_0008d690(unsigned int size);

struct Holder_5a510 {
    char pad0[0x104];
    void *anim;
};

struct Res_5a510 {
    char pad00[0x330];
    Holder_5a510 *primary;
    Holder_5a510 *secondary;
};

struct Resolver_5a510 {
    Res_5a510 *FUN_00059a30();
};

struct Target_5a510 {
    Resolver_5a510 *FUN_000592a0();
};

struct Effect_5a510 {
    Effect_5a510 *FUN_0001d9b0(void *anim, int a, int b);
};

class CGrappleDamageTrack {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual Effect_5a510 *vfunc_12(Target_5a510 *target);
    char pad04[0xc];
    int paramA;
    int paramB;
};

Effect_5a510 *CGrappleDamageTrack::vfunc_12(Target_5a510 *target) {
    if (target == 0) {
        return 0;
    }
    Resolver_5a510 *resolver = target->FUN_000592a0();
    if (resolver == 0) {
        return 0;
    }
    Res_5a510 *res = resolver->FUN_00059a30();
    if (res == 0) {
        return 0;
    }
    Holder_5a510 *holder = res->secondary;
    if (holder == 0) {
        holder = res->primary;
        if (holder == 0) {
            return 0;
        }
    }
    void *anim = holder->anim;
    if (anim == 0) {
        return 0;
    }
    Effect_5a510 *mem = (Effect_5a510 *)FUN_0008d690(0x28);
    if (mem == 0) {
        return 0;
    }
    return mem->FUN_0001d9b0(anim, paramA, paramB);
}
