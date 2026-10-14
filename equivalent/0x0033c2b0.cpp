// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 16/16)
// FUN_0033c2b0 @ 0x0033c2b0
void __cdecl FUN_00338e20(void* L, const char* fmt, ...);
struct MatchState {
    char pad0[8];
    void* L;
};
// equiv-conv: FUN_0033c2b0 edi eax
const char* FUN_0033c2b0(MatchState* ms, const char* p) {
    char c = *p++;
    if (c == '%') {
        if (*p == 0)
            FUN_00338e20(ms->L, "malformed pattern (ends with `%%')");
        return p + 1;
    }
    if (c == '[') {
        if (*p == '^')
            p++;
        do {
            if (*p == 0)
                FUN_00338e20(ms->L, "malformed pattern (missing `]')");
            if (*(p++) == '%' && *p != 0)
                p++;
        } while (*p != ']');
        return p + 1;
    }
    return p;
}
