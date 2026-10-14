// equiv-dead: +0x63 taken: this == -4 never happens (lea ecx, [esi + 4]; test ecx, ecx: the source's if (&tag))
extern "C" char *strncpy(char *, const char *, unsigned int);
extern "C" long atol(const char *);
extern "C" int sprintf(char *, const char *, ...);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern char DAT_004e5a68[0x100];

struct Source {
    char *FUN_002666f0();
};

struct Tag {
    int unused;
};

class Holder {
public:
    char pad00[4];
    Tag tag;
    char pad08[0x1c];
    char name[0xac8];
    Source *source;
    char pad_af0[2];
    char shortForm;
    char disabled;

    char *FUN_00203a80();
};

char *Holder::FUN_00203a80()
{
    struct Frame {
        char buf[0x100];
        volatile unsigned int cookie;
    } fr;
    fr.cookie = DAT_004d9968;
    if (!source || disabled) {
        __security_check_cookie(fr.cookie);
        return 0;
    }
    strncpy(fr.buf, source->FUN_002666f0(), 0x100);
    Tag *t = &tag;
    if (t) {
        char *end = fr.buf;
        while (*end)
            end++;
        end -= 4;
        *end = 0;
        if (shortForm)
            sprintf(DAT_004e5a68, "%s_district_%d", name, atol(end - 1));
        else
            sprintf(DAT_004e5a68, "%s_r%03d", name, atol(end - 3));
    } else {
        char *p = fr.buf;
        while (*p)
            p++;
        p--;
        while (*p != 'C')
            p--;
        char *q = DAT_004e5a68;
        while ((*q++ = *p++) != 0)
            ;
        char *dot = DAT_004e5a68;
        while (*dot != '.')
            dot++;
        *dot = 0;
    }
    __security_check_cookie(fr.cookie);
    return DAT_004e5a68;
}
