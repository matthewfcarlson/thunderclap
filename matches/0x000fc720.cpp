extern "C" char DAT_0040cfb4[];
typedef unsigned char u8;
typedef unsigned int u32;
struct Ref {
    virtual void a();
    virtual void b();
};
struct CActorAgent {
    u32 vt;
    char pad[0x54];
    Ref* mRef;
    void Cleanup();
    CActorAgent* vfunc_2(u8 flag);
};
extern void thunk(CActorAgent*);
CActorAgent* CActorAgent::vfunc_2(u8 flag) {
    vt = ((int)DAT_0040cfb4);
    mRef->b();
    mRef = 0;
    Cleanup();
    if (flag & 1)
        thunk(this);
    return this;
}
