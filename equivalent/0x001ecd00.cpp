// STATUS: equivalent (tools/equiv.py level 3: 464 inputs, branch coverage 6/6)
// FUN_001ecd00 @ 0x001ecd00
// FUN_001ecd00: build "crush_<name>" and hand it to FUN_001ec980
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" char *__cdecl strcat(char *dst, const char *src);

class Crusher {
public:
    void FUN_001ec980(int a, const char *name);
    void FUN_001ecd00(const char *name, int a);
};

void Crusher::FUN_001ecd00(const char *name, int a)
{
    struct Frame {
        char buf[70];
        char pad[2];
        unsigned int cookie;
    } f = { "crush_" };
    f.cookie = DAT_004d9968;
    if (name != 0) {
        strcat(f.buf, name);
        FUN_001ec980(a, f.buf);
    }
    __security_check_cookie(f.cookie);
}
