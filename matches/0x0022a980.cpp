extern "C" char DAT_00427534[];
extern int gCount_22a980;
extern int gHigh;
struct Base_22a980 {
    void Init(int);
};
struct LocomotionDriver : Base_22a980 {
    int vptr;
    char pad[0x1b];
    int a;
    int b;
    LocomotionDriver* Init(int);
};
LocomotionDriver* LocomotionDriver::Init(int x) {
    Base_22a980::Init(x);
    a = 0;
    b = 0;
    vptr = ((int)DAT_00427534);
    int n = ++gCount_22a980;
    if (n > gHigh)
        gHigh = n;
    return this;
}