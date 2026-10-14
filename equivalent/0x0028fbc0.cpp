// STATUS: equivalent (tools/equiv.py level 3: 3058 inputs, branch coverage 29/36, incomplete)
// FUN_0028fbc0 @ 0x0028fbc0
struct Source {
    const char *FUN_003469f5();
};

extern "C" Source *__cdecl FUN_003449e4(const char *name);

// Strips a leading "class " keyword and any namespace qualifier ("A::B::") from a type name,
// copying the remainder to `out`. Fails (and terminates `out`) when it does not fit.
bool FUN_0028fbc0(const char *name, char *out, unsigned int size)
{
    char buf[0x100];
    if (!name)
        return false;
    const char *src = FUN_003449e4(name)->FUN_003469f5();
    char *dst = buf;
    char c;
    do {
        c = *src++;
        *dst++ = c;
    } while (c);

    char *p = buf;
    if (buf[0] == ' ') {
        do {
            p++;
        } while (*p == ' ');
    }
    if (p[0] == 'c' && p[1] == 'l' && p[2] == 'a' && p[3] == 's' && p[4] == 's')
        p += 5;
    if (*p == ' ') {
        do {
            p++;
        } while (*p == ' ');
    }
    if (*p) {
        const char *s = p;
        c = *s;
        do {
            if (c == ':' && s[1] == ':')
                p = (char *)s + 2;
            c = s[1];
            s++;
        } while (c);
    }
    unsigned int len = 0;
    while (p[len])
        len++;
    if (len >= size - 1) {
        *out = 0;
        return false;
    }
    const char *from = p;
    do {
        c = *from++;
        *out++ = c;
    } while (c);
    return true;
}
