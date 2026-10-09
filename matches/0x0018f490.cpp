// Same code shape as 0x0015cb40 (propagated; names are from that function)
struct Sub1;
struct Sub2;
struct Mid {
    Sub1* A();
    Sub2* B();
};
struct Mgr {
    Mid* Get();
};
struct Sub1 {
    void Init(int a, int b);
};
struct Sub2 {
    void Fin(int a);
};

class HeliLocomotionAction {
  public:
    char pad[0x20];
    Mgr* mMgr;
    int mVal;
    void vfunc_4();
};

void HeliLocomotionAction::vfunc_4() {
    Mid* m = mMgr->Get();
    Sub1* s = m->A();
    if (s) {
        s->Init(mVal, 0);
        Sub2* t = m->B();
        if (t)
            t->Fin(0);
    }
}
