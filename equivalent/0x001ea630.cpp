// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CSoundResourceManager::vfunc_3 @ 0x001ea630
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct Text {
    char data[0x2c];
    void FUN_00247270(const char *s, int len, int flags);
};
struct Handle {
    char data[0xa0];
    void FUN_002458f0(Text *src);
};
int __cdecl FUN_00246100(Handle *h);

struct Frame {
    Text text;
    Handle handle;
    unsigned int cookie;
};

class CSoundResourceManager {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(const char *name, int unused);
    void FUN_001ea5a0(int id);
};

void CSoundResourceManager::vfunc_3(const char *name, int unused)
{
    Frame f;
    f.cookie = DAT_004d9968;
    int len = 0;
    while (name[len] != 0)
        len++;
    f.text.FUN_00247270(name, len, 0);
    f.handle.FUN_002458f0(&f.text);
    FUN_001ea5a0(FUN_00246100(&f.handle));
    __security_check_cookie(f.cookie);
}
