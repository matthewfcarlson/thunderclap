// STATUS: equivalent (tools/equiv.py level 3: 2793 inputs, branch coverage 6/6)
// FUN_001ebea0 @ 0x001ebea0
extern "C" char *strcat(char *dst, const char *src);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

class Crusher {
public:
    void FUN_001ebd80(int arg2, const char *name, float strength, int flag);
    void FUN_001ebea0(const char *suffix, int arg2);
};

void Crusher::FUN_001ebea0(const char *suffix, int arg2)
{
    struct Frame {
        char name[0x46];
        unsigned int cookie;
    } fr = { "crush_" };
    fr.cookie = DAT_004d9968;
    if (suffix != 0) {
        strcat(fr.name, suffix);
        FUN_001ebd80(arg2, fr.name, 100.0f, 0);
    }
    __security_check_cookie(fr.cookie);
}
