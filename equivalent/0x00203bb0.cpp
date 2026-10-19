// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 7/7)
// FUN_00203bb0 @ 0x00203bb0
// cl-flags: /GS
extern "C" char *strncpy(char *, const char *, unsigned int);
extern "C" long atol(const char *);

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
    } fr;
    if (!source) {
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
    return v;
}
