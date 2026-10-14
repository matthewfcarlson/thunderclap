struct Sub1_15cb40;
struct Sub2_15cb40;
struct Mid_15cb40 {
    Sub1_15cb40* A();
    Sub2_15cb40* B();
};
struct Mgr_15cb40 {
    Mid_15cb40* Get();
};
struct Sub1_15cb40 {
    void Init(int a, int b);
};
struct Sub2_15cb40 {
    void Fin(int a);
};

class HeliLocomotionAction {
  public:
    char pad[0x20];
    Mgr_15cb40* mMgr;
    int mVal;
    void vfunc_4();
};

void HeliLocomotionAction::vfunc_4() {
    Mid_15cb40* m = mMgr->Get();
    Sub1_15cb40* s = m->A();
    if (s) {
        s->Init(mVal, 0);
        Sub2_15cb40* t = m->B();
        if (t)
            t->Fin(0);
    }
}
