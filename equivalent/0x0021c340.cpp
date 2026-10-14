// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 6/6)
// FUN_0021c340 @ 0x0021c340
// Lua 5.0 check_match: expect token `what`, else report an error (mentioning `who` and its line).
struct Token_21c340 {
    int token;
    int seminfo;
};

struct LexState_21c340 {
    int current;
    int linenumber;
    int lastline;
    Token_21c340 t;                    // 0x0c
    Token_21c340 lookahead;            // 0x14
    void *fs;                   // 0x1c
    void *L;                    // 0x20
};

int __cdecl FUN_0021bbc0(LexState_21c340 *ls, int *seminfo);                // llex
const char *__cdecl FUN_0021af00(LexState_21c340 *ls, int token);           // token2str
const char *__cdecl FUN_00216320(void *L, const char *fmt, ...);     // luaO_pushfstring
void __cdecl FUN_0021b060(LexState_21c340 *ls, const char *msg);            // lexerror

// equiv-conv: FUN_0021c340 eax esi edi stack
void FUN_0021c340(int where, LexState_21c340 *ls, int what, int who) {
    if (ls->t.token == what) {
        ls->lastline = ls->linenumber;
        if (ls->lookahead.token != 287) {
            ls->t.token = ls->lookahead.token;
            ls->t.seminfo = ls->lookahead.seminfo;
            ls->lookahead.token = 287;
        } else {
            ls->t.token = FUN_0021bbc0(ls, &ls->t.seminfo);
        }
        return;
    }
    if (where == ls->linenumber) {
        FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected", FUN_0021af00(ls, what)));
    } else {
        FUN_0021b060(ls, FUN_00216320(ls->L, "`%s' expected (to close `%s' at line %d)",
                                      FUN_0021af00(ls, what), FUN_0021af00(ls, who), where));
    }
}
