// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00261830 @ 0x00261830
const char *__cdecl FUN_002611b0(const char *s);
float __cdecl FUN_00260d00(const char *s);
void __cdecl FUN_00260be0(const char *s, float v);

void FUN_00261830(const char *s)
{
    float t = FUN_00260d00(FUN_002611b0(s));
    const char *p = FUN_002611b0(s);
    while (*p != 0) {
        float f = FUN_00260d00(p);
        if (f != 0.0f)
            t = t / f;
        p = FUN_002611b0(s);
    }
    FUN_00260be0(s, t);
}
