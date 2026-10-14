struct Thing_171060 {
    int pad[4];
    int value;
};
struct ObjC_171060 {
    void run(int);
};
struct ObjB_171060 {
    ObjC_171060* run();
};
struct ObjA_171060 {
    ObjB_171060* run();
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
    Thing_171060* field1c;
    ObjA_171060* field20;
};
bool LocomotionStateAction::vfunc_5(int param, int unused) {
    if (param)
        return true;
    ObjB_171060* b = field20->run();
    ObjC_171060* c = b->run();
    c->run(field1c->value);
    return false;
}
