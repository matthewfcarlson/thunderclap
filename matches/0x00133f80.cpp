struct A_133f80 {
    A_133f80* First();
    A_133f80* Second();
    void Third(int);
};
class HoverAction {
  public:
    char pad[0x1c];
    int mValue;
    int mThing;
    bool vfunc_5(int, int);
};
bool HoverAction::vfunc_5(int param, int unused) {
    if (param == 0) {
        A_133f80* p = ((A_133f80*)*(void**)((char*)this + 0x20))->First();
        p = p->Second();
        if (mValue > 0)
            p->Third(1);
        else
            p->Third(3);
    }
    return true;
}