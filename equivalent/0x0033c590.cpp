// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 17/18, incomplete)
// FUN_0033c590 @ 0x0033c590
// Lua 5.0 lstrlib max_expand
struct MatchState_33c590 {
    const char *src_init;
    const char *src_end;
    void *L;
    int level;
};

const char *FUN_0033c7e0(MatchState_33c590 *ms, const char *s, const char *p);
// equiv-conv: FUN_0033c430 ebx eax stack
int FUN_0033c430(int c, const char *p, const char *ec);
// equiv-conv: FUN_0033c320 eax edi
int FUN_0033c320(int c, int cl);

// equiv-conv: FUN_0033c590 eax stack stack stack
const char *FUN_0033c590(const char *p, MatchState_33c590 *ms, const char *s, const char *ep)
{
    int i = 0;
    while (s + i < ms->src_end) {
        int c = (unsigned char)s[i];
        int ok;
        switch (*p) {
        case '%':
            ok = FUN_0033c320(c, p[1]);
            break;
        case '.':
            ok = 1;
            break;
        case '[':
            ok = FUN_0033c430(c, p, ep - 1);
            break;
        default:
            ok = (unsigned char)*p == c;
            break;
        }
        if (!ok)
            break;
        i++;
    }
    while (i >= 0) {
        const char *res = FUN_0033c7e0(ms, s + i, ep + 1);
        if (res != 0)
            return res;
        i--;
    }
    return 0;
}
