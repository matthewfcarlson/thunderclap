// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 5/6, incomplete)
// pure3d::CompressedQuaternionChannel<math::CompressedQuaternion4>::vfunc_5 @ 0x0028d920
struct Quat_28d920 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_28d920 *a, const Quat_28d920 *b, float t);
};

struct CompressedQuaternion4 {
    short v[2];
    Quat_28d920 *FUN_0028d820(Quat_28d920 *tmp);
};

struct Frame_28d920 {
    int lo;
    int hi;
    Quat_28d920 q1;
    Quat_28d920 q0;
    Quat_28d920 tmp;
};

class CompressedQuaternionChannel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(float time, Quat_28d920 *out);
    virtual void vfunc_6();
    void *field04;
    char pad08[0x10 - 8];
    int count;
    short *times;
    CompressedQuaternion4 *values;
    char FUN_00289f80(float time, int *lo, int *hi);
};

void CompressedQuaternionChannel::vfunc_5(float time, Quat_28d920 *out)
{
    Frame_28d920 f;

    if (FUN_00289f80(time, &f.lo, &f.hi) && field04 != 0) {
        float dt = time - (float)times[f.lo];
        if (dt != 0.0f) {
            int hi = f.hi;
            int span = times[hi] - times[f.lo];
            float frac = dt / (float)span;
            CompressedQuaternion4 *vals = values;
            f.q0 = *vals[f.lo].FUN_0028d820(&f.tmp);
            f.q1 = *vals[hi].FUN_0028d820(&f.tmp);
            out->FUN_0022b750(&f.q0, &f.q1, frac);
            return;
        }
        *out = *values[f.lo].FUN_0028d820(&f.q0);
        return;
    }
    *out = *values[f.lo].FUN_0028d820(&f.tmp);
}
