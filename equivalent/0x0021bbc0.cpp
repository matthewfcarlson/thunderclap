// STATUS: equivalent (tools/equiv.py level 3: 660 inputs, branch coverage 68/89, incomplete)
// FUN_0021bbc0 @ 0x0021bbc0
// FUN_0021bbc0 @ 0x0021bbc0
// equiv-conv: FUN_0021b0d0 esi
// equiv-conv: FUN_0021b480 eax
// equiv-conv: FUN_0021b520 ecx eax stack
// equiv-conv: FUN_0021b230 eax stack
// equiv-conv: FUN_0021b1c0 edi
// equiv-conv: FUN_0021b720 ecx stack stack

struct Zio_21bbc0 {
    unsigned int n;
    const unsigned char *p;
};

struct Buff {
    char *buffer;
    int n;
};

struct TString_21bbc0 {
    char pad0[6];
    unsigned char reserved;
};

struct SemInfo_21bbc0 {
    TString_21bbc0 *ts;
};

struct LexState_21bbc0 {
    int current;
    char pad4[0x24 - 4];
    Zio_21bbc0 *z;
    Buff *buff;
};

extern "C" int __cdecl FUN_0021a550(Zio_21bbc0 *z);
void FUN_0021b0d0(LexState_21bbc0 *ls);
extern "C" int __cdecl FUN_0021b480(void *);
extern "C" void __cdecl FUN_0021b520(void *, int, void *);
void FUN_0021b230(LexState_21bbc0 *ls, SemInfo_21bbc0 *seminfo);
void FUN_0021b1c0(LexState_21bbc0 *ls);
void FUN_0021b720(LexState_21bbc0 *ls, int del, SemInfo_21bbc0 *seminfo);
extern "C" TString_21bbc0 *__cdecl FUN_0021b080(LexState_21bbc0 *ls, const char *str, int len);
extern "C" void __cdecl FUN_0021afd0(LexState_21bbc0 *ls, const char *msg, int token);
extern "C" int isspace(int c);
extern "C" int isdigit(int c);
extern "C" int isalpha(int c);
extern "C" int isalnum(int c);

static int Zgetc(LexState_21bbc0 *ls)
{
    unsigned int n = ls->z->n;
    ls->z->n = n - 1;
    if (n > 0) {
        Zio_21bbc0 *z = ls->z;
        const unsigned char *p = z->p;
        int c = *p;
        z->p = p + 1;
        return c;
    }
    return FUN_0021a550(ls->z);
}

extern "C" int FUN_0021bbc0(void *ls, void *seminfo)
{
    ((LexState_21bbc0 *)ls)->buff->n = 0;
    for (;;) {
        int c = ((LexState_21bbc0 *)ls)->current;
        switch (c) {
        case '\n':
        case '\r':
            FUN_0021b0d0(((LexState_21bbc0 *)ls));
            continue;
        case '-': {
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            if (((LexState_21bbc0 *)ls)->current != '-')
                return '-';
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            if (((LexState_21bbc0 *)ls)->current == '[') {
                int sep = FUN_0021b480((LexState_21bbc0 *)((LexState_21bbc0 *)ls));
                ((LexState_21bbc0 *)ls)->buff->n = 0;
                if (sep >= 0) {
                    FUN_0021b520((LexState_21bbc0 *)((LexState_21bbc0 *)ls), sep, (SemInfo_21bbc0 *)0);
                    ((LexState_21bbc0 *)ls)->buff->n = 0;
                    continue;
                }
            }
            if (((LexState_21bbc0 *)ls)->current == '\n')
                continue;
            for (;;) {
                if (((LexState_21bbc0 *)ls)->current == '\r')
                    break;
                if (((LexState_21bbc0 *)ls)->current == -1)
                    break;
                ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
                if (((LexState_21bbc0 *)ls)->current == '\n')
                    break;
            }
            continue;
        }
        case '[': {
            int sep = FUN_0021b480((LexState_21bbc0 *)((LexState_21bbc0 *)ls));
            if (sep >= 0) {
                FUN_0021b520((LexState_21bbc0 *)((LexState_21bbc0 *)ls), sep, (SemInfo_21bbc0 *)((SemInfo_21bbc0 *)seminfo));
                return 0x11e;
            }
            if (sep == -1)
                return '[';
            FUN_0021afd0(((LexState_21bbc0 *)ls), "invalid long string delimiter", 0x11e);
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            if (((LexState_21bbc0 *)ls)->current != '=')
                return '=';
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            return 0x119;
        }
        case '=':
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            if (((LexState_21bbc0 *)ls)->current != '=')
                return '=';
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            return 0x119;
        case '<':
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            if (((LexState_21bbc0 *)ls)->current != '=')
                return '<';
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            return 0x11b;
        case '>':
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            if (((LexState_21bbc0 *)ls)->current != '=')
                return '>';
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            return 0x11a;
        case '~':
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            if (((LexState_21bbc0 *)ls)->current != '=')
                return '~';
            ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
            return 0x11c;
        case '"':
        case '\'':
            FUN_0021b720(((LexState_21bbc0 *)ls), ((LexState_21bbc0 *)ls)->current, ((SemInfo_21bbc0 *)seminfo));
            return 0x11e;
        case '.':
            FUN_0021b1c0(((LexState_21bbc0 *)ls));
            if (((LexState_21bbc0 *)ls)->current == '.') {
                ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
                if (((LexState_21bbc0 *)ls)->current != '.')
                    return 0x117;
                ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
                return 0x118;
            }
            if (!isdigit(((LexState_21bbc0 *)ls)->current))
                return '.';
            FUN_0021b230(((LexState_21bbc0 *)ls), ((SemInfo_21bbc0 *)seminfo));
            return 0x11d;
        case -1:
            return 0x11f;
        default:
            if (isspace(c)) {
                ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
                continue;
            }
            if (isdigit(((LexState_21bbc0 *)ls)->current)) {
                FUN_0021b230(((LexState_21bbc0 *)ls), ((SemInfo_21bbc0 *)seminfo));
                return 0x11d;
            }
            if (!isalpha(((LexState_21bbc0 *)ls)->current)) {
                int ch = ((LexState_21bbc0 *)ls)->current;
                if (ch != '_') {
                    ((LexState_21bbc0 *)ls)->current = Zgetc(((LexState_21bbc0 *)ls));
                    return ch;
                }
            }
            do {
                FUN_0021b1c0(((LexState_21bbc0 *)ls));
            } while (isalnum(((LexState_21bbc0 *)ls)->current) || ((LexState_21bbc0 *)ls)->current == '_');
            TString_21bbc0 *ts = FUN_0021b080(((LexState_21bbc0 *)ls), ((LexState_21bbc0 *)ls)->buff->buffer, ((LexState_21bbc0 *)ls)->buff->n);
            unsigned char r = ts->reserved;
            if (r > 0)
                return r + 0x100;
            ((SemInfo_21bbc0 *)seminfo)->ts = ts;
            return 0x116;
        }
    }
}
