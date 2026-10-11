// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 18/18)
// FUN_00271870 @ 0x00271870
extern unsigned short DAT_004cdc08[32];
int __cdecl FUN_002716f0(unsigned int, char *, unsigned int, int, unsigned int *, unsigned int);
int __cdecl FUN_00271870(unsigned int, char *, unsigned int, unsigned int, unsigned int *, unsigned int);

int __cdecl ConvertWithFallback(unsigned int codepoint, char *output, unsigned int capacity, unsigned int fallback, unsigned int *written, unsigned int flags)
{
    if (capacity == 0)
        return -1;
    if (FUN_002716f0(codepoint, output, capacity, 0, written, flags) == 0)
        return 0;
    if (codepoint >= 0xa0 && codepoint <= 0xff) {
        *output = (char)codepoint;
        *written = 1;
        return 0;
    }
    for (unsigned int i = 0; i < 32; ++i) {
        if (codepoint == DAT_004cdc08[i]) {
            *output = (char)(i + 0x80);
            *written = 1;
            return 0;
        }
    }
    if (fallback == 0)
        return -4;
    int result = FUN_00271870(fallback, output, capacity, 0, written, flags);
    return result == -2 ? -6 : result;
}
