// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 26/26)
// FUN_002697c0 @ 0x002697c0
extern "C" char * __cdecl strchr(const char *, int);
extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
extern "C" void __cdecl FUN_00270b70(char *);
extern "C" int __cdecl FUN_00345b90(int);
extern "C" void __cdecl FUN_00267660(char *);

void __cdecl FUN_002697c0(const char *source, char *output, char *workspace, char **suffix, const char **remainder)
{
    char *prefix = workspace ? workspace : output;
    const char *colon = strchr(source, ':');
    unsigned int length;
    const char *rest;
    if (colon) {
        length = (unsigned int)(colon - source + 1);
        strncpy(prefix, source, length);
        prefix[length] = 0;
        rest = source + length;
    } else {
        FUN_00270b70(prefix);
        length = 0;
        while (prefix[length]) ++length;
        rest = source;
    }
    if (remainder) *remainder = rest;
    for (char *p = prefix; *p; ++p)
        *p = (char)FUN_00345b90((signed char)*p);
    if (output) {
        char *dst = output;
        const char *src = prefix;
        do { *dst++ = *src; } while (*src++);
        if (suffix) *suffix = output + length;
        char *tail = output + length;
        dst = tail;
        src = rest;
        do { *dst++ = *src; } while (*src++);
        for (char *p = tail; *p; ++p)
            if (*p == '/') *p = '\\';
        FUN_00267660(tail);
    }
}