// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000fb740 @ 0x000fb740
void __cdecl FUN_000fb740(short *dest, const char *src, int count)
{
    if (*src != 0) {
        int i = 0;
        do {
            if (i == count - 1)
                break;
            *dest++ = (short)*src++;
            ++i;
        } while (*src != 0);
    }
    *dest = 0;
}
