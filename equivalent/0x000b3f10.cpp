// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 28/34, incomplete)
// FEControllerSystem::vfunc_1 @ 0x000b3f10
struct Pad {
    void FUN_000ada70(float *state);
};

extern int DAT_0049f31c, DAT_0049f320, DAT_0049f324, DAT_0049f328;
extern int DAT_0049f32c, DAT_0049f330, DAT_0049f334, DAT_0049f338;
extern int DAT_0049f33c, DAT_0049f340, DAT_0049f344, DAT_0049f348;
extern int DAT_0049f34c, DAT_0049f350;

static void accumulate(float *out, const float *s, const int &srcIdx, const int &dstIdx)
{
    int si = srcIdx;
    int di = dstIdx;
    out[di] = s[si] + out[di];
    int d2 = dstIdx;
    float v = out[d2];
    out[d2] = (v < 1.0f) ? v : 1.0f;
}

static void addClamped(float *dst, float v)
{
    *dst = v + *dst;
    float r = *dst;
    *dst = (r < 1.0f) ? r : 1.0f;
}

class FEControllerSystem {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(int index, float *out);
    Pad *pads[1];           // 0x4
};

void FEControllerSystem::vfunc_1(int index, float *out)
{
    if (index >= 1)
        return;
    float s[17];
    pads[index]->FUN_000ada70(s);
    out[0] = 0.0f; out[1] = 0.0f; out[2] = 0.0f; out[3] = 0.0f; out[4] = 0.0f;
    out[5] = 0.0f; out[6] = 0.0f; out[7] = 0.0f; out[8] = 0.0f; out[9] = 0.0f;
    accumulate(out, s, DAT_0049f31c, DAT_0049f320);
    accumulate(out, s, DAT_0049f324, DAT_0049f328);
    accumulate(out, s, DAT_0049f32c, DAT_0049f330);
    accumulate(out, s, DAT_0049f334, DAT_0049f338);
    accumulate(out, s, DAT_0049f33c, DAT_0049f340);
    accumulate(out, s, DAT_0049f344, DAT_0049f348);
    accumulate(out, s, DAT_0049f34c, DAT_0049f350);
    for (int k = 0; k < 2; k++) {
        float a = s[11 + 2 * k];
        float neg = (0.0f < -a) ? -a : 0.0f;
        addClamped(&out[0], neg);
        float pos = (0.0f < a) ? a : 0.0f;
        addClamped(&out[1], pos);
        float b = s[12 + 2 * k];
        float negb = (0.0f < -b) ? -b : 0.0f;
        addClamped(&out[3], negb);
        float posb = (0.0f < b) ? b : 0.0f;
        addClamped(&out[2], posb);
    }
}
