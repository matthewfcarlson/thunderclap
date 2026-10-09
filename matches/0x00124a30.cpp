class Condition {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
class Param {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class TargetFirstShotCondition : public Condition, public Param {
  public:
    virtual void vfunc_0();
    virtual void vfunc_5();
    virtual unsigned char vfunc_6(void*, void*, void*);
};
extern int RTTI_Params;
extern int RTTI_CFightParams;
extern int __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Actor {
    char pad[0x1b74];
    unsigned char flag;
};
struct Obj {
    Actor* FUN_000592a0();
};
struct ActorRef {
    int FUN_00059a30();
};
unsigned char TargetFirstShotCondition::vfunc_6(void* a, void* b, void* c) {
    if (FUN_00344e74(b, 0, &RTTI_Params, &RTTI_CFightParams, 0)) {
        Actor* p = ((Obj*)b)->FUN_000592a0();
        int x = ((ActorRef*)p)->FUN_00059a30();
        if (x) {
            unsigned char old = *(unsigned char*)(x + 0x1b74);
            *(unsigned char*)(x + 0x1b74) = 1;
            return old;
        }
    }
    return 0;
}