// STATUS: equivalent (tools/equiv.py level 3: 158 inputs, branch coverage 47/48, incomplete)
// FUN_0021b720 @ 0x0021b720
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int isdigit(int c);

struct ZIO {
    unsigned int n;
    const unsigned char *p;
};

struct Mbuffer {
    char *buffer;
    unsigned int n;
    unsigned int buffsize;
};

struct TString_21b720 {
    char pad0[0x10];
    char str[1];
};

struct Table;

struct FuncState_21b720 {
    char pad0[4];
    Table *h;
};

struct TValue_21b720 {
    int tt;
    int value;
};

struct SemInfo_21b720 {
    TString_21b720 *ts;
};

struct LexState_21b720 {
    int current;            // 0x00
    int linenumber;         // 0x04
    char pad08[0x1c - 8];
    FuncState_21b720 *fs;          // 0x1c
    void *L;                // 0x20
    ZIO *z;                 // 0x24
    Mbuffer *buff;          // 0x28
    TString_21b720 *source;        // 0x2c
};

int __cdecl FUN_0021a550(ZIO *z);
char *__cdecl FUN_0021add0(void *L, char *p, unsigned int oldsize, unsigned int newsize);
void __cdecl FUN_0021afd0(LexState_21b720 *ls, const char *msg, int token);
void __cdecl FUN_00216340(char *out, const char *source, unsigned int len);
const char *__cdecl FUN_00216320(void *L, const char *fmt, ...);
void __cdecl FUN_002152b0(void *L, int code);
TString_21b720 *__cdecl FUN_00219430(void *L, const char *s, unsigned int len);
TValue_21b720 *__cdecl FUN_0021a500(void *L, Table *t, TString_21b720 *key);

// save_and_next with the lexer state in edi
// equiv-conv: FUN_0021b1c0 edi
void FUN_0021b1c0(LexState_21b720 *ls);
// inclinenumber with the lexer state in esi
// equiv-conv: FUN_0021b0d0 esi
void FUN_0021b0d0(LexState_21b720 *ls);

#define SAVE(c)                                                                           \
    do {                                                                                  \
        Mbuffer *b = ls->buff;                                                            \
        if (b->n + 1 > b->buffsize) {                                                     \
            unsigned int old = b->buffsize;                                               \
            b->buffer = FUN_0021add0(ls->L, b->buffer, old, old * 2 + 0x20);              \
            b->buffsize = b->buffsize * 2 + 0x20;                                         \
        }                                                                                 \
        b->buffer[b->n] = (char)(c);                                                      \
        b->n++;                                                                           \
    } while (0)

#define NEXT()                                                                            \
    do {                                                                                  \
        ZIO *z = ls->z;                                                                   \
        if (z->n-- > 0)                                                                   \
            ls->current = *z->p++;                                                        \
        else                                                                              \
            ls->current = FUN_0021a550(ls->z);                                            \
    } while (0)

// Lexer: read a quoted string up to the delimiter del, handling escapes; the lexer state arrives in ecx.
// equiv-conv: FUN_0021b720 ecx stack stack
void FUN_0021b720(LexState_21b720 *ls, int del, SemInfo_21b720 *seminfo)
{
    unsigned int cookie = DAT_004d9968;
    char buf[80];
    FUN_0021b1c0(ls);
    while (ls->current != del) {
        switch (ls->current) {
        case -1:
            FUN_0021afd0(ls, "unfinished string", 0x11f);
            break;
        case '\n':
        case '\r': {
            FUN_00216340(buf, ls->source->str, 80);
            const char *msg = FUN_00216320(ls->L, "%s:%d: %s", buf, ls->linenumber, "unfinished string");
            SAVE(0);
            FUN_00216320(ls->L, "%s near `%s'", msg, ls->buff->buffer);
            FUN_002152b0(ls->L, 3);
            break;
        }
        case '\\': {
            NEXT();
            int c;
            switch (ls->current) {
            case 'a': c = 7; break;
            case 'b': c = 8; break;
            case 'f': c = 12; break;
            case 'n': c = 10; break;
            case 'r': c = 13; break;
            case 't': c = 9; break;
            case 'v': c = 11; break;
            case '\n':
            case '\r':
                SAVE('\n');
                FUN_0021b0d0(ls);
                continue;
            case -1:
                continue;
            default:
                if (!isdigit(ls->current)) {
                    FUN_0021b1c0(ls);
                } else {
                    int i = 0;
                    c = 0;
                    do {
                        c = 10 * c + (ls->current - '0');
                        NEXT();
                    } while (++i < 3 && isdigit(ls->current));
                    if (c > 255)
                        FUN_0021afd0(ls, "escape sequence too large", 0x11e);
                    SAVE(c);
                }
                continue;
            }
            SAVE(c);
            NEXT();
            continue;
        }
        default:
            SAVE(ls->current);
            NEXT();
            break;
        }
    }
    FUN_0021b1c0(ls);
    void *L = ls->L;
    TString_21b720 *ts = FUN_00219430(L, ls->buff->buffer + 1, ls->buff->n - 2);
    TValue_21b720 *o = FUN_0021a500(L, ls->fs->h, ts);
    if (o->tt == 0) {
        o->value = 1;
        o->tt = 1;
    }
    seminfo->ts = ts;
    __security_check_cookie(cookie);
}
