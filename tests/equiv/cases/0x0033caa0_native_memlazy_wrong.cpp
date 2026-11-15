// (tri3, strlazy) wrong: returns the match one byte late
// bytes (a fuzzed n: no mapping for them, ours faulted intrinsic_access) where the original stops at the first difference.
extern "C" void *__cdecl memchr(const void *, int, unsigned int);
extern "C" int __cdecl memcmp(const void *, const void *, unsigned int);
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
        if (memcmp(init, s2 + 1, l2) == 0)
            return init;
        l1 -= init - s1;
        s1 = init;
    }
    return 0;
}
