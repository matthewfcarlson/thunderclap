// STATUS: equivalent (tools/equiv.py level 3: 122 inputs, branch coverage 44/48, incomplete)
// _strncat @ 0x003468c0
char *__cdecl FUN_003468c0(char *dest, const char *src, unsigned int count)
{
    char *d = dest;
    if (count == 0)
        return dest;
    while (*d != 0)
        d++;
    while (count != 0) {
        char c = *src++;
        *d++ = c;
        if (c == 0)
            return dest;
        count--;
    }
    *d = 0;
    return dest;
}
