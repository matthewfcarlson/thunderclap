extern int gValue_11c900;
class StrafeRunAction {
  public:
    char pad[0x2c];
    int mValue;
    bool vfunc_3(int, int);
};
bool StrafeRunAction::vfunc_3(int a, int b) {
    int value = gValue_11c900;
    if (value > 8)
        value = 1;
    mValue = value;
    gValue_11c900 = value + 1;
    return true;
}