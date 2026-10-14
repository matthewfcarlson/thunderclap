// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 7/7)
// FUN_00203bb0 @ 0x00203bb0
extern "C" char *strncpy(char *, const char *, unsigned int);
extern "C" long atol(const char *);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct Source_203bb0 {
    char *FUN_002666f0();
};

struct Tag {
    int unused;
};

class Holder_203bb0 {
public:
    char pad00[4];
    Tag tag;
    char pad08[0xae4];
    Source_203bb0 *source;
    char pad_af0[2];
    char shortForm;

    int FUN_00203bb0();
};

int Holder_203bb0::FUN_00203bb0()
{
    struct Frame {
        char small[0x20];
        char buf[0x100];
        volatile unsigned int cookie;
    } fr;
    fr.cookie = DAT_004d9968;
    if (!source) {
        __security_check_cookie(fr.cookie);
        return -1;
    }
    strncpy(fr.buf, source->FUN_002666f0(), 0x100);
    Tag *t = &tag;
    if (t) {
        char *end = fr.buf;
        while (*end)
            end++;
        end -= 4;
        *end = 0;
        long v = atol(shortForm ? end - 1 : end - 3);
        __security_check_cookie(fr.cookie);
        return v;
    }
    char *p = fr.buf;
    while (*p)
        p++;
    p--;
    while (*p != 'R')
        p--;
    p++;
    char *q = fr.small;
    while ((*q++ = *p++) != 0)
        ;
    char *dot = fr.small;
    while (*dot != '.')
        dot++;
    *dot = 0;
    long v = atol(fr.small);
    __security_check_cookie(fr.cookie);
    return v;
}
