// (rev4, strlazy) must fail: memcmp does not stop at a NUL. lmemfind with strncmp in place of memcmp: equal bytes up to
// a shared NUL with a difference after it are a match for strncmp and none for memcmp.
extern "C" void *__cdecl memchr(const void *, int, unsigned int);
extern "C" int __cdecl strncmp(const char *, const char *, unsigned int);
// equiv-conv: FUN_0033caa0 eax stack stack stack
const char *FUN_0033caa0(const char *s1, unsigned int l1, const char *s2, unsigned int l2)
{
    if (l2 == 0)
        return s1;
    if (l2 > l1)
        return 0;
    l2--;
    l1 = l1 - l2;
    while (l1 > 0) {
        const char *init = (const char *)memchr(s1, *s2, l1);
        if (init == 0)
            break;
        init++;
        if (strncmp(init, s2 + 1, l2) == 0)
            return init - 1;
        l1 -= init - s1;
        s1 = init;
    }
    return 0;
}
