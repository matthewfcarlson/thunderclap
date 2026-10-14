// STATUS: equivalent (tools/equiv.py level 3: 2528 inputs, branch coverage 10/12, incomplete)
// FUN_0033caa0 @ 0x0033caa0
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
            return init - 1;
        l1 -= init - s1;
        s1 = init;
    }
    return 0;
}
