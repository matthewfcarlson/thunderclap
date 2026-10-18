extern "C" char FUN_002674f0(const char*, const char*);
extern "C" char FUN_002674f0(const char* pattern, const char* text) {
    const signed char* s = (const signed char*)pattern;
    const signed char* p = (const signed char*)text;
    int c = *s, a = *p;
    for (;;) {
        if (!a)
            return (char)(c == 0);
        if (c && a != '*' && a != '?' && c != a)
            return 0;
        if (!c && a != '*')
            return 0;
        if (a == '*') {
            ++p;
            if (!*p)
                return 1;
            do {
                if (FUN_002674f0((const char*)s, (const char*)p))
                    return 1;
                if (!*s)
                    return 0;
                ++s;
            } while (1);
        }
        ++p;
        ++s;
        c = *s;
        a = *p;
    }
}