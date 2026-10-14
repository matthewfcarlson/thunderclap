// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0021afd0 @ 0x0021afd0
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct lua_State;
struct TString {
    char pad00[0x10];
    char str[1];
};
struct LexState {
    char pad00[4];
    int linenumber;
    char pad08[0x18];
    lua_State *L;
    char pad24[8];
    TString *source;
};

void __cdecl FUN_00216340(char *out, const char *source, int bufflen);
const char *__cdecl FUN_00216320(lua_State *L, const char *fmt, ...);
void __cdecl FUN_002152b0(lua_State *L, int errcode);
// equiv-conv: FUN_0021af60 eax edi
const char *FUN_0021af60(int token, LexState *ls);

void FUN_0021afd0(LexState *ls, const char *msg, int token)
{
    unsigned int cookie = DAT_004d9968;
    char buff[0x50];
    FUN_00216340(buff, ls->source->str, 0x50);
    const char *s = FUN_00216320(ls->L, "%s:%d: %s", buff, ls->linenumber, msg);
    if (token)
        FUN_00216320(ls->L, "%s near `%s'", s, FUN_0021af60(token, ls));
    FUN_002152b0(ls->L, 3);
    __security_check_cookie(cookie);
}
