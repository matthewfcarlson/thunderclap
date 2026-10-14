class First_1c3dc0 {
  public:
    void Cleanup();
};
class Obj_1c3dc0 {
  public:
    virtual void v0();
    virtual void v1();
};
void thunk_FUN_00267090(First_1c3dc0*);
class Target_1c3dc0 {
  public:
    First_1c3dc0* volatile mFirst;
    char pad[0x6c];
    Obj_1c3dc0* volatile m70;
    Obj_1c3dc0* volatile m74;
    void F();
};
void Target_1c3dc0::F() {
    First_1c3dc0* p = mFirst;
    if (p) {
        p->Cleanup();
        thunk_FUN_00267090(p);
    }
    mFirst = 0;
    Obj_1c3dc0* a = m70;
    if (a) {
        a->v1();
        m70 = 0;
    }
    Obj_1c3dc0* b = m74;
    if (b) {
        b->v1();
        m74 = 0;
    }
}