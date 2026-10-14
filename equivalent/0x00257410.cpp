// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 10/10)
// audio::Sequence::vfunc_3 @ 0x00257410
struct Stream {
    char pad0[0x24];
    int indent;
};

bool __cdecl FUN_00246f50(Stream *s, const char *fmt, ...);

namespace audio {
class Sequence {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(Stream **w);
    bool FUN_00257320(Stream **w);
    bool FUN_00257290(Stream **w);
};
}

bool audio::Sequence::vfunc_3(Stream **w)
{
    if (!FUN_00246f50(*w, "Version %d\n", 1))
        return false;
    if (!FUN_00246f50(*w, "[\n"))
        return false;
    (*w)->indent++;
    if (!FUN_00257320(w))
        return false;
    if (!FUN_00257290(w))
        return false;
    (*w)->indent--;
    if (!FUN_00246f50(*w, "]\n"))
        return false;
    return true;
}
