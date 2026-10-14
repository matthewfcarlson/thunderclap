// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 14/14)
// FUN_0033c640 @ 0x0033c640
// Lua 5.0 lstrlib min_expand
struct MatchState_33c640 {
    const char *src_init;
    const char *src_end;
    void *L;
    int level;
};

const char *FUN_0033c7e0(MatchState_33c640 *ms, const char *s, const char *p);
// equiv-conv: FUN_0033c430 ebx eax stack
int FUN_0033c430(int c, const char *p, const char *ec);
// equiv-conv: FUN_0033c320 eax edi
int FUN_0033c320(int c, int cl);

// equiv-conv: FUN_0033c640 eax stack stack stack
const char *FUN_0033c640(const char *s, MatchState_33c640 *ms, const char *p, const char *ep)
{
    for (;;) {
        const char *res = FUN_0033c7e0(ms, s, ep + 1);
        if (res != 0)
            return res;
        if (s >= ms->src_end)
            return 0;
        int c = (unsigned char)*s;
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
            return 0;
        s++;
    }
}
