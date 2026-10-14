// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 16/16)
// FUN_002176c0 @ 0x002176c0
struct lua_State_2176c0;

typedef unsigned int Instruction;

struct TObject_2176c0 {
    int tt;
    void *value;
};

struct Proto_2176c0 {
    char pad00[0xc];
    Instruction *code;          // 0xc
    char pad10[4];
    int *lineinfo;              // 0x14
};

struct LClosure {
    char pad00[0xc];
    Proto_2176c0 *p;                   // 0xc
};

struct CallInfo_2176c0 {
    TObject_2176c0 *base;              // 0x0
    char pad04[4];
    Instruction *savedpc;       // 0x8
};

struct lua_State_2176c0 {
    char pad00[0x14];
    CallInfo_2176c0 *ci;               // 0x14
    char pad18[0x18];
    unsigned char hookmask;     // 0x30
    char pad31[3];
    int basehookcount;          // 0x34
    int hookcount;              // 0x38
};

void __cdecl FUN_00215520(lua_State_2176c0 *L, int event, int line);

// Lua 5.0 traceexec: L arrives in ebx and the new pc in edi.
// equiv-conv: FUN_002176c0 ebx edi
void FUN_002176c0(lua_State_2176c0 *L, Instruction *pc)
{
    unsigned char mask = L->hookmask;
    CallInfo_2176c0 *ci = L->ci;
    Instruction *oldpc = ci->savedpc;
    ci->savedpc = pc;

    if (mask > 4 && L->hookcount == 0) {
        L->hookcount = L->basehookcount;
        FUN_00215520(L, 3, -1);
        return;
    }

    if (mask & 4) {
        Proto_2176c0 *p = ((LClosure *)ci->base[-1].value)->p;
        int npc = (int)(pc - p->code) - 1;
        int newline = p->lineinfo ? p->lineinfo[npc] : 0;
        if (npc == 0 || pc <= oldpc ||
            newline != (p->lineinfo ? p->lineinfo[(int)(oldpc - p->code) - 1] : 0))
            FUN_00215520(L, 2, newline);
    }
}
