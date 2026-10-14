// STATUS: equivalent (tools/equiv.py level 3: 123 inputs, branch coverage 8/8)
// FUN_002017d0 @ 0x002017d0
// Looks a property name up in the global key table; outputs its two table values.
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct Key_2017d0 {
    unsigned int lo, hi;
};
extern Key_2017d0 DAT_004e5928[];
extern int DAT_004c8fb8;
extern int DAT_004c8f90[];
extern int DAT_004c8fa4[];

bool FUN_002017d0(const char *name, int *outIndex, int *outValue)
{
    union {
        unsigned __int64 q;
        unsigned int w[2];
    } h;
    h.q = FUN_002672f0(name, 0, 0);
    int n = DAT_004c8fb8;
    *outValue = 0;
    *outIndex = -1;
    for (int i = 0; i < n; i++) {
        if (DAT_004e5928[i].lo == h.w[0] && DAT_004e5928[i].hi == h.w[1]) {
            *outValue = DAT_004c8f90[i];
            *outIndex = DAT_004c8fa4[i];
            return true;
        }
    }
    return false;
}
