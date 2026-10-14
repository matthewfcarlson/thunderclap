// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00225be0 @ 0x00225be0
float __cdecl FUN_0004af40(float lo, float hi, float v);

// Clamp v into [lo, hi] (bounds may be given in either order), or wrap it into the range.
float FUN_00225be0(float v, float lo, float hi, bool wrap)
{
    if (wrap)
        return FUN_0004af40(lo, hi, v);
    if (hi > lo) {
        if (v < lo)
            return lo;
        if (v > hi)
            return hi;
        return v;
    }
    if (v > lo)
        return lo;
    if (v < hi)
        return hi;
    return v;
}
