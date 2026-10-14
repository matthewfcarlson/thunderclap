extern "C" char DAT_00414030[];
extern void* __cdecl Allocate(unsigned int);
class CollisionDevastatorCondition {
  public:
    int vptr;
    char pad[8];
    char flag;
    CollisionDevastatorCondition(int);
};
class Factory_159350 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual CollisionDevastatorCondition* F();
};
CollisionDevastatorCondition* Factory_159350::F() {
    CollisionDevastatorCondition* p = (CollisionDevastatorCondition*)Allocate(0x10);
    if (p) {
        p->CollisionDevastatorCondition::CollisionDevastatorCondition(0);
        p->vptr = ((int)DAT_00414030);
        p->flag = 1;
        return p;
    }
    return 0;
}