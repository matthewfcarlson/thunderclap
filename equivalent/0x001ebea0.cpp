// STATUS: equivalent (tools/equiv.py level 3: 16329 inputs, branch coverage 6/6)
// FUN_001ebea0 @ 0x001ebea0
// cl-flags: /GS
// equiv-map: ___security_cookie = 0x004d9968
extern "C" char *strcat(char *dst, const char *src);

class Crusher_1ebea0 {
public:
    void FUN_001ebd80(int arg2, const char *name, float strength, int flag);
    void FUN_001ebea0(const char *suffix, int arg2);
};

void Crusher_1ebea0::FUN_001ebea0(const char *suffix, int arg2)
{
    struct Frame {
        char name[0x46];
    } fr = { "crush_" };
    if (suffix != 0) {
        strcat(fr.name, suffix);
        FUN_001ebd80(arg2, fr.name, 100.0f, 0);
    }
}
