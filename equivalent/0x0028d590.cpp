// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 5/6, incomplete)
// pure3d::CompressedQuaternionChannel<math::CompressedQuaternion6>::vfunc_5 @ 0x0028d590
struct Quat {
    float x, y, z, w;
    void FUN_0022b750(const Quat *a, const Quat *b, float t);
};

struct CompressedQuaternion6 {
    short v[3];
    Quat *FUN_001db820(Quat *tmp);
};

struct Frame {
    int lo;
    int hi;
    Quat q1;
    Quat q0;
    Quat tmp;
};

class CompressedQuaternionChannel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float time, Quat *out);
    virtual void vfunc_6();
    void *field04;
    char pad08[0x10 - 8];
    int count;
    short *times;
    CompressedQuaternion6 *values;
    char FUN_00289f80(float time, int *lo, int *hi);
};

void CompressedQuaternionChannel::vfunc_5(float time, Quat *out)
{
    Frame f;

    if (FUN_00289f80(time, &f.lo, &f.hi) && field04 != 0) {
        float dt = time - (float)times[f.lo];
        if (dt != 0.0f) {
            int hi = f.hi;
            int span = times[hi] - times[f.lo];
            float frac = dt / (float)span;
            CompressedQuaternion6 *vals = values;
            f.q0 = *vals[f.lo].FUN_001db820(&f.tmp);
            f.q1 = *vals[hi].FUN_001db820(&f.tmp);
            out->FUN_0022b750(&f.q0, &f.q1, frac);
            return;
        }
        *out = *values[f.lo].FUN_001db820(&f.q0);
        return;
    }
    *out = *values[f.lo].FUN_001db820(&f.tmp);
}
