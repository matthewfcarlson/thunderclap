// STATUS: equivalent (tools/equiv.py level 3: 316 inputs, branch coverage 14/14)
// FUN_000f7790 @ 0x000f7790
// Unescapes \b \n \s (zero width space) in place, returns the new length.
int __stdcall FUN_000f7790(unsigned short* text) {
    unsigned short* dst = text;
    unsigned short* src = text;
    int count = 0;
    if (*src != 0) {
        do {
            unsigned short c = *src;
            if (c == '\\') {
                src++;
                c = *src;
                if (c == 0) {
                    *dst++ = '\\';
                    count++;
                    break;
                }
                if (c == 'b')
                    c = 8;
                else if (c == 'n')
                    c = 10;
                else if (c == 's')
                    c = 0x200c;
            }
            *dst++ = c;
            src++;
            count++;
        } while (*src != 0);
    }
    *dst = 0;
    return count;
}
