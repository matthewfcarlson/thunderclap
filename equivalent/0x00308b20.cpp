// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// FUN_00308b20 @ 0x00308b20
struct Vec3_308b20 { float x, y, z; };

class Sink_308b20 {
public:
    virtual bool v0(int a, float b, int c);
};

class Mover_308b20 {
public:
    virtual void v0(Vec3_308b20* out, Vec3_308b20* in1, Vec3_308b20* in2);
    char pad04[0x28];
    Sink_308b20 sink;
    char pad30[0x10];
    float f40;
    int f44;
    char pad48[4];
    float f4c;
    char pad50[0xc];
    char busy;
    char dirty;
    bool FUN_00308b20();
};

bool Mover_308b20::FUN_00308b20() {
    char wasBusy = busy;
    dirty = 0;
    if (wasBusy)
        return false;
    float a = f40;
    float b = f4c;
    Vec3_308b20 hi = { b, b, b };
    Vec3_308b20 lo = { a, a, a };
    float half = b;
    v0(&lo, &hi, &hi);
    return (&sink)->v0(f44, 0.5f * half, 0);
}
