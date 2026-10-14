namespace pure3d {
struct Base_2886c0 {
    Base_2886c0(const Base_2886c0& o);
    virtual void v0();
    char p[0x10c];
};
struct PoseAnimationController : Base_2886c0 {
    int i110;
    int i114;
    int i118;
    int i11c;
    char pad[0x11];
    char c131;
    char pad2[2];
    int i134;
    char pad3[0x10];
    int i148;
    int i14c;
    PoseAnimationController(const PoseAnimationController& o);
    void Set(int);
    virtual void v1();
};
PoseAnimationController::PoseAnimationController(const PoseAnimationController& o) : Base_2886c0(o) {
    i110 = 0;
    i114 = 0x3f800000;
    i118 = 0;
    i148 = 0xffff;
    i14c = 0;
    i11c = 0;
    i134 = 0;
    Set(o.i110);
    c131 = o.c131;
    i14c = o.i14c;
}
} // namespace pure3d
