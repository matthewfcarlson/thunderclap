// Same code shape as 0x0015cb40 (propagated; names are from that function)
struct Sub1_18f490;
struct Sub2_18f490;
struct Mid_18f490 {
    Sub1_18f490* A();
    Sub2_18f490* B();
};
struct Mgr_18f490 {
    Mid_18f490* Get();
};
struct Sub1_18f490 {
    void Init(int a, int b);
};
struct Sub2_18f490 {
    void Fin(int a);
};

class HeliLocomotionAction {
  public:
    char pad[0x20];
    Mgr_18f490* mMgr;
    int mVal;
    void vfunc_4();
};

void HeliLocomotionAction::vfunc_4() {
    Mid_18f490* m = mMgr->Get();
    Sub1_18f490* s = m->A();
    if (s) {
        s->Init(mVal, 0);
        Sub2_18f490* t = m->B();
        if (t)
            t->Fin(0);
    }
}
