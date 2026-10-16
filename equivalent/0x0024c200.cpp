// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 12/12)
// FUN_0024c200 @ 0x0024c200
struct Entry { int value; const char *name; char unused[16]; };
extern Entry DAT_004cc248[6];
int __cdecl FUN_0024c200(const char *name)
{
    for (unsigned i = 0; i < 6; ++i) {
        const char *a = name;
        const char *b = DAT_004cc248[i].name;
        while (*a && *a == *b) { ++a; ++b; }
        if (*a == *b) return DAT_004cc248[i].value;
    }
    return 7;
}