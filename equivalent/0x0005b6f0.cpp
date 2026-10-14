// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0005b6f0 @ 0x0005b6f0
inline void *operator new(unsigned int, void *p) { return p; }

struct Base12 {
    char data[12];
    void FUN_00236d40();
};
struct Name8 {
    int lo, hi;
    void FUN_0027af00();
};

class CGrappleLocoStrafe4Track {
public:
    virtual void vfunc_0();
    int f04;
    int f08;
    int f0c;
    int f10;
    char pad14[4];
    Name8 n18, n20, n28, n30, n38, n40, n48, n50, n58, n60, n68;
    int f70, f74, f78;

    CGrappleLocoStrafe4Track() {}
    CGrappleLocoStrafe4Track *FUN_0005b6f0();
};

CGrappleLocoStrafe4Track *CGrappleLocoStrafe4Track::FUN_0005b6f0()
{
    ((Base12 *)this)->FUN_00236d40();
    new (this) CGrappleLocoStrafe4Track;
    f0c = 0;
    f10 = 0;
    n18.FUN_0027af00();
    n20.FUN_0027af00();
    n28.FUN_0027af00();
    n30.FUN_0027af00();
    n38.FUN_0027af00();
    n40.FUN_0027af00();
    n48.FUN_0027af00();
    n50.FUN_0027af00();
    n58.FUN_0027af00();
    n60.FUN_0027af00();
    n68.FUN_0027af00();
    f70 = 0;
    f74 = 0;
    f78 = 0;
    return this;
}
