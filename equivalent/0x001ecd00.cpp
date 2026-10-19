// STATUS: equivalent (tools/equiv.py level 3: 16479 inputs, branch coverage 6/6)
// FUN_001ecd00 @ 0x001ecd00
// cl-flags: /GS
// equiv-map: ___security_cookie = 0x004d9968
// FUN_001ecd00: build "crush_<name>" and hand it to FUN_001ec980
extern "C" char *__cdecl strcat(char *dst, const char *src);

class Crusher_1ecd00 {
public:
    void FUN_001ec980(int a, const char *name);
    void FUN_001ecd00(const char *name, int a);
};

void Crusher_1ecd00::FUN_001ecd00(const char *name, int a)
{
    struct Frame {
        char buf[70];
        char pad[2];
    } f = { "crush_" };
    if (name != 0) {
        strcat(f.buf, name);
        FUN_001ec980(a, f.buf);
    }
}
