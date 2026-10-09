extern int gCount;
extern int gHigh;
struct Base {
    void Init(int);
};
struct LocomotionDriver : Base {
    int vptr;
    char pad[0x1b];
    int a;
    int b;
    LocomotionDriver* Init(int);
};
LocomotionDriver* LocomotionDriver::Init(int x) {
    Base::Init(x);
    a = 0;
    b = 0;
    vptr = 0x427534;
    int n = ++gCount;
    if (n > gHigh)
        gHigh = n;
    return this;
}