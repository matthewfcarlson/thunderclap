class PropAnimationAction {
  public:
    char pad[0x24];
    struct X {
        char pad2[0x40];
        int value;
    }* m;
    bool vfunc_5(int, int);
};
bool PropAnimationAction::vfunc_5(int x, int y) {
    bool b = false;
    if (m)
        b = (m->value != -1);
    return !b;
}