struct X {
    X* a();
    X* b();
    int d(int);
    void e(int);
};
extern X* __cdecl FUN_0027f250();
class MotionTrailStopAction {
  public:
    char pad00[0x1c];
    struct A {
        char pad[0x10];
        int value;
    }* mA;
    int mCheck;
    void vfunc_4();
};
void MotionTrailStopAction::vfunc_4() {
    if (mCheck) {
        X* a = ((X*)mCheck)->a();
        X* b = a->b();
        X* c = FUN_0027f250();
        int t = mA->value;
        int v = b->d(t);
        c->e(v);
    }
}