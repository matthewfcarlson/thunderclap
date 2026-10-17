// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000f72e0 @ 0x000f72e0
// equiv-conv: FUN_000f72e0 eax ebx
unsigned short *FUN_000f72e0(unsigned short *text, const char *pattern)
{
    while (*text != 0) {
        const char *candidate = pattern;
        const unsigned short *wide = text;
        while (*candidate != 0 && *wide != 0 && (int)(signed char)*candidate == (unsigned int)*wide) {
            ++candidate;
            ++wide;
        }
        if (*candidate == 0)
            return text;
        ++text;
    }
    return 0;
}