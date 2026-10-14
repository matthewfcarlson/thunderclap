// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 16/16)
// FUN_0033c520 @ 0x0033c520
struct State;

struct MatchState_33c520 {
    char pad0[4];
    const char *src_end;    // 0x4
    State *L;               // 0x8
};

void FUN_00338e20(State *L, const char *msg);

// equiv-conv: FUN_0033c520 eax ecx ebx
const char *FUN_0033c520(const char *p, const char *s, MatchState_33c520 *ms)
{
    if (*p == 0 || p[1] == 0)
        FUN_00338e20(ms->L, "unbalanced pattern");
    if (*s != *p)
        return 0;
    int b = *p;
    int e = p[1];
    int cont = 1;
    const char *end = ms->src_end;
    while (++s < end) {
        int c = *s;
        if (c == e) {
            if (--cont == 0)
                return s + 1;
        } else if (c == b) {
            cont++;
        }
    }
    return 0;
}
