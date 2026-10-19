// STATUS: equivalent (tools/equiv.py level 3: 20031 inputs, branch coverage 56/56)
// FUN_002899e0 @ 0x002899e0
double __cdecl FUN_00047970(float x);
extern "C" double fmod(double, double);

float __cdecl FUN_000186b0(float *v, float *lo, float *hi);

float FUN_002899e0(float *p, char *st, float v, float step, float lo, float hi, char flag, int mode)
{
    if (step == 0.0f)
        return v;
    if (mode == 1)
        return v;
    if (*p == 0.0f)
        return v;
    float range = hi - lo;
    v = FUN_000186b0(&v, &lo, &hi);
    float t = *p - step;
    *p = t;
    if (range <= 1e-05f)
        return v;

    switch (mode) {
    case 2: {
        *st = 1;
        if (flag == 0 && *p <= 0.0f) {
            *p = 0;
            return hi;
        }
        double vp = (double)v + step;
        v = (float)vp;
        if (!(vp > hi))
            return vp;
        return fmod(v - hi, range) + lo;
    }
    case 3: {
        *st = 0;
        if (flag == 0 && *p <= 0.0f) {
            *p = 0;
            return lo;
        }
        double vp = (double)v - step;
        v = (float)vp;
        if (!(vp < lo))
            return vp;
        return fmod(v - lo, range) + hi;
    }
    case 4:
        if (flag == 0 && t <= 0.0f) {
            *p = 0;
            return lo;
        }
        break;
    case 5:
        if (flag == 0 && t <= 0.0f) {
            *p = 0;
            return hi;
        }
        break;
    default: {
        *st = 1;
        double vp = (double)v + step;
        v = (float)vp;
        if (!(vp > hi))
            return vp;
        if (flag != 1) {
            *p = 0;
            return hi;
        }
        return fmod(v - lo, range) + lo;
    }
    }

    if (*st == 1) {
        double vp = (double)v + step;
        if (!(vp > hi))
            return vp;
        step = range + range;
        volatile float tt = (float)((vp - hi) / step);
        double fr = (double)tt - FUN_00047970(tt);
        if (!(fr > 0.5f)) {
            *st = 0;
            return hi - fr * step;
        }
        return (fr - 0.5f) * step + lo;
    }
    double vp = (double)v - step;
    if (!(vp < lo))
        return vp;
    step = range + range;
    volatile float tt = (float)((vp - lo) / step);
    if (tt < 0)
        tt = -tt;
    double fr = (double)tt - FUN_00047970(tt);
    if (fr > 0.5f)
        return hi - (fr - 0.5f) * step;
    *st = 1;
    return fr * step + lo;
}
