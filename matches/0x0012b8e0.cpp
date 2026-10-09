struct Obj { int Fn(int); };
struct Inner { char pad[8]; Obj* obj8; };
struct Outer { char pad[0x20]; Inner* inner; };
extern Outer* gGlobal;

class ThreatBallAction {
public:
    char pad[0x1c];
    int mValue;
    int mGuard;
    int mResult;
    bool vfunc_3(void*, void*);
};

bool ThreatBallAction::vfunc_3(void*, void*) {
    if (!mGuard) return false;
    Obj* o = gGlobal->inner->obj8;
    mResult = o->Fn(mValue + 0x30);
    return true;
}
