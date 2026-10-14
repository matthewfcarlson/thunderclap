// STATUS: equivalent (tools/equiv.py level 3: 3080 inputs, branch coverage 12/16, incomplete)
// FUN_00214900 @ 0x00214900
// Lua 5.0 luaG addinfo: prefixes "chunk:line: " to the message when the running function is a Lua function
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);

struct Proto {
    char pad0[0xc];
    unsigned int *code;         // 0x0c
    char pad10[4];
    int *lineinfo;              // 0x14
    char pad18[8];
    char *source;               // 0x20
};

struct Closure {
    char pad0[6];
    unsigned char isC;          // 0x06
    char pad07[5];
    Proto *p;                   // 0x0c
};

struct TObject {
    int tt;
    Closure *value;
};

struct CallInfo {
    TObject *base;              // 0x00
    TObject *top;               // 0x04
    unsigned int *savedpc;      // 0x08
    int tailcalls;              // 0x0c
};

struct lua_State {
    char pad0[0x14];
    CallInfo *ci;               // 0x14
};

void __cdecl FUN_00216340(char *out, const char *source, int bufflen);
const char *FUN_00216320(lua_State *L, const char *fmt, ...);

// equiv-conv: FUN_00214900 ebx stack
void FUN_00214900(lua_State *L, const char *msg)
{
    struct Frame {
        char buff[60];
        unsigned int cookie;
    } fr;
    fr.cookie = DAT_004d9968;
    CallInfo *ci = L->ci;
    TObject *func = ci->base - 1;
    if (func->tt == 6 && func->value->isC == 0) {
        Proto *p = func->value->p;
        int pc = (int)(ci->savedpc - p->code) - 1;
        int line;
        if (pc < 0)
            line = -1;
        else if (p->lineinfo != 0)
            line = p->lineinfo[pc];
        else
            line = 0;
        FUN_00216340(fr.buff, p->source + 0x10, 60);
        FUN_00216320(L, "%s:%d: %s", fr.buff, line, msg);
    }
    __security_check_cookie(fr.cookie);
}
