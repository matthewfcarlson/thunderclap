struct Obj_12b8e0 {
    int Fn(int);
};
struct Inner_12b8e0 {
    char pad[8];
    Obj_12b8e0* obj8;
};
struct Outer_12b8e0 {
    char pad[0x20];
    Inner_12b8e0* inner;
};
extern Outer_12b8e0* gGlobal_12b8e0;

class ThreatBallAction {
  public:
    char pad[0x1c];
    int mValue;
    int mGuard;
    int mResult;
    bool vfunc_3(void*, void*);
};

bool ThreatBallAction::vfunc_3(void*, void*) {
    if (!mGuard)
        return false;
    Obj_12b8e0* o = gGlobal_12b8e0->inner->obj8;
    mResult = o->Fn(mValue + 0x30);
    return true;
}
