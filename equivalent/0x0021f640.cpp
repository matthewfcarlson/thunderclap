// STATUS: equivalent (tools/equiv.py level 3: 2720 inputs, branch coverage 12/12)
// FUN_0021f640 @ 0x0021f640
// FUN_0021f640 @ 0x0021f640: Lua 5.0 parser rule chunk(): { stat [';'] } with a nesting-depth guard
struct FuncState {
    char pad00[0x24];
    int freereg;
    char pad28[0x34 - 0x28];
    unsigned char nactvar;
};

struct LexState {
    char pad0[4];
    int linenumber;
    int lastline;
    int token;
    int seminfo;
    int lookaheadToken;
    int lookaheadSeminfo;
    FuncState *fs;
    char pad20[0x30 - 0x20];
    int nestlevel;
};

int FUN_0021bbc0(LexState *ls, int *seminfo);
void FUN_0021afd0(LexState *ls, const char *msg, int token);
// equiv-conv: FUN_0021f500 eax
int FUN_0021f500(LexState *ls);

static void next(LexState *ls)
{
    ls->lastline = ls->linenumber;
    if (ls->lookaheadToken != 0x11f) {
        ls->token = ls->lookaheadToken;
        ls->seminfo = ls->lookaheadSeminfo;
        ls->lookaheadToken = 0x11f;
    } else {
        ls->token = FUN_0021bbc0(ls, &ls->seminfo);
    }
}

// TK_ELSE, TK_ELSEIF, TK_END, TK_UNTIL, TK_EOS
static bool block_follow(int token)
{
    switch (token) {
    case 0x104:
    case 0x105:
    case 0x106:
    case 0x114:
    case 0x11f:
        return true;
    default:
        return false;
    }
}

void FUN_0021f640(LexState *ls)
{
    ls->nestlevel++;
    if (ls->nestlevel > 200)
        FUN_0021afd0(ls, "chunk has too many syntax levels", 0);

    while (!block_follow(ls->token)) {
        int islast = FUN_0021f500(ls);
        if (ls->token == ';')
            next(ls);
        ls->fs->freereg = ls->fs->nactvar;
        if (islast)
            break;
    }
    ls->nestlevel--;
}
