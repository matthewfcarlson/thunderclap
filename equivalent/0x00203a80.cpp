// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 9/9)
// FUN_00203a80 @ 0x00203a80
// cl-flags: /GS
#include "decls/data/game/global.h"

extern "C" char *strncpy(char *, const char *, unsigned int);
extern "C" long atol(const char *);
extern "C" int sprintf(char *, const char *, ...);

struct Source_203a80 {
    char *FUN_002666f0();
};

struct Tag {
    int unused;
};

class Holder_203a80 {
public:
    char pad00[4];
    Tag tag;
    char pad08[0x1c];
    char name[0xac8];
    Source_203a80 *source;
    char pad_af0[2];
    char shortForm;
    char disabled;

    char *FUN_00203a80();
};

char *Holder_203a80::FUN_00203a80()
{
    struct Frame {
        char buf[0x100];
    } fr;
    if (!source || disabled) {
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
            sprintf(((char*)&DAT_004e5a68), "%s_district_%d", name, atol(end - 1));
        else
            sprintf(((char*)&DAT_004e5a68), "%s_r%03d", name, atol(end - 3));
    } else {
        char *p = fr.buf;
        while (*p)
            p++;
        p--;
        while (*p != 'C')
            p--;
        char *q = ((char*)&DAT_004e5a68);
        while ((*q++ = *p++) != 0)
            ;
        char *dot = ((char*)&DAT_004e5a68);
        while (*dot != '.')
            dot++;
        *dot = 0;
    }
    return ((char*)&DAT_004e5a68);
}
