extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

int __cdecl FUN_00294c70(const char* src, unsigned short* dst, int max);

class TextSink {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual float Measure(unsigned short* wide);    // slot 10
    float FUN_000dfbf0(const char* text);
};

float TextSink::FUN_000dfbf0(const char* text)
{
    struct Frame {
        unsigned short wide[0x200];
        unsigned int cookie;
    } f;
    f.cookie = DAT_004d9968;
    if (text == 0) {
        __security_check_cookie(f.cookie);
        return 0.0f;
    }
    FUN_00294c70(text, f.wide, 0x200);
    float r = Measure(f.wide);
    __security_check_cookie(f.cookie);
    return r;
}
