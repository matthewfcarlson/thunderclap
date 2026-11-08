// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 6/6)
// FUN_0033c4d0 @ 0x0033c4d0
// lstrlib singlematch(c, p, ep)
// equiv-conv: FUN_0033c320 eax edi
int FUN_0033c320(int c, int cl);
// equiv-conv: FUN_0033c430 ebx eax stack
int FUN_0033c430(int c, const char *p, const char *ec);
// equiv-conv: FUN_0033c4d0 eax ecx stack
int FUN_0033c4d0(const char *p, int c, const char *ep)
{
    unsigned char pc = (unsigned char)*p;
    if (pc == '%')
        return FUN_0033c320(c, (signed char)p[1]);
    if (pc == '.')
        return 1;
    if (pc == '[')
        return FUN_0033c430(c, p, ep - 1);
    return pc == (unsigned int)c;
}
