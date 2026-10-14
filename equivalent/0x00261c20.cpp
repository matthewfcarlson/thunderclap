// STATUS: equivalent (tools/equiv.py level 3: 952 inputs, branch coverage 8/8)
// FUN_00261c20 @ 0x00261c20
struct Stream {
    char pad0[0x24];
    int indent;
};

bool __cdecl FUN_00246f50(Stream *s, const char *fmt, ...);
bool __cdecl FUN_0024eb60(Stream **w, const char *name, void *value);

class Fraction {
public:
    int numerator;
    int denominator;
    bool FUN_00261c20(Stream **w);
};

bool Fraction::FUN_00261c20(Stream **w)
{
    if (!FUN_00246f50(*w, "\n[\n"))
        return false;
    (*w)->indent++;
    if (!FUN_0024eb60(w, "mNumerator", this))
        return false;
    if (!FUN_0024eb60(w, "mDenominator", &denominator))
        return false;
    (*w)->indent--;
    if (!FUN_00246f50(*w, "]"))
        return false;
    return true;
}
