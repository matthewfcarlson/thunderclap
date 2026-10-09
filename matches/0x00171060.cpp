struct Thing {
    int pad[4];
    int value;
};
struct ObjC {
    void run(int);
};
struct ObjB {
    ObjC* run();
};
struct ObjA {
    ObjB* run();
};
class LocomotionStateAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int param, int unused);
    char pad[0x1c - 4];
    Thing* field1c;
    ObjA* field20;
};
bool LocomotionStateAction::vfunc_5(int param, int unused) {
    if (param)
        return true;
    ObjB* b = field20->run();
    ObjC* c = b->run();
    c->run(field1c->value);
    return false;
}
