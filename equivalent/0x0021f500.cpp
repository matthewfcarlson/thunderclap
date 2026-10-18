// STATUS: equivalent (tools/equiv.py level 3: 20028 inputs, branch coverage 14/14)
// FUN_0021f500 @ 0x0021f500
// FUN_0021f500 @ 0x0021f500
// Lua 5.0 lparser statement(): returns 1 when the statement must be the last of its block.
struct LexState_21f500 {
    char pad0[4];
    int linenumber;
    int lastline;
    int token;
};

// equiv-conv: FUN_0021c190 esi
void FUN_0021c190(LexState_21f500 *ls);
// equiv-conv: FUN_0021c290 esi ecx
int FUN_0021c290(LexState_21f500 *ls, int token);
// equiv-conv: FUN_0021c340 eax esi edi stack
void FUN_0021c340(int line, LexState_21f500 *ls, int what, int who);
// equiv-conv: FUN_0021e080 eax
void FUN_0021e080(LexState_21f500 *ls);
void FUN_0021e300(LexState_21f500 *ls, int line);
// equiv-conv: FUN_0021e5b0 eax stack
void FUN_0021e5b0(LexState_21f500 *ls, int line);
// equiv-conv: FUN_0021ecd0 eax stack
void FUN_0021ecd0(LexState_21f500 *ls, int line);
// equiv-conv: FUN_0021ee70 eax stack
void FUN_0021ee70(LexState_21f500 *ls, int line);
// equiv-conv: FUN_0021ef60 ebx
void FUN_0021ef60(LexState_21f500 *ls);
// equiv-conv: FUN_0021f0a0 eax
void FUN_0021f0a0(LexState_21f500 *ls);
// equiv-conv: FUN_0021f280 eax esi
void FUN_0021f280(LexState_21f500 *ls, int line);
// equiv-conv: FUN_0021f300 eax
void FUN_0021f300(LexState_21f500 *ls);
// equiv-conv: FUN_0021f350 eax
void FUN_0021f350(LexState_21f500 *ls);
// equiv-conv: FUN_0021f460 edi
void FUN_0021f460(LexState_21f500 *ls);

// equiv-conv: FUN_0021f500 eax
int FUN_0021f500(LexState_21f500 *ls)
{
    int line = ls->linenumber;
    switch (ls->token) {
    case 0x10a:     // if
        FUN_0021ee70(ls, line);
        return 0;
    case 0x115:     // while
        FUN_0021e300(ls, line);
        return 0;
    case 0x103:     // do
        FUN_0021c190(ls);
        FUN_0021e080(ls);
        FUN_0021c340(line, ls, 0x106, 0x103);
        return 0;
    case 0x108:     // for
        FUN_0021ecd0(ls, line);
        return 0;
    case 0x110:     // repeat
        FUN_0021e5b0(ls, line);
        return 0;
    case 0x109:     // function
        FUN_0021f280(ls, line);
        return 0;
    case 0x10c:     // local
        FUN_0021c190(ls);
        if (FUN_0021c290(ls, 0x109))
            FUN_0021ef60(ls);
        else
            FUN_0021f0a0(ls);
        return 0;
    case 0x111:     // return
        FUN_0021f350(ls);
        return 1;
    case 0x102:     // break
        FUN_0021f460(ls);
        return 1;
    default:
        FUN_0021f300(ls);
        return 0;
    }
}
