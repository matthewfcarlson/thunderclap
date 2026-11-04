// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 4/4)
// FUN_0021c2e0 @ 0x0021c2e0
struct Parser { char pad0[4]; int position; int previous; int token; int value; int lookahead; int lookaheadValue; char pad1[4]; int errorContext; };
extern "C" int __cdecl FUN_0021bbc0(void *, void *);
int __cdecl FUN_0021af00(Parser *, int);
int __cdecl FUN_00216320(int, const char *, ...);
void __cdecl FUN_0021b060(Parser *, int);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(void * parser_, int expected)
{
    Parser * parser = (Parser *)parser_;
    if (parser->token != expected) {
        int name = FUN_0021af00(parser, expected);
        int error = FUN_00216320(parser->errorContext, "`%s' expected", name);
        FUN_0021b060(parser, error);
        return;
    }
    parser->previous = parser->position;
    if (parser->lookahead != 0x11f) {
        parser->token = parser->lookahead;
        parser->value = parser->lookaheadValue;
        parser->lookahead = 0x11f;
    } else {
        parser->token = FUN_0021bbc0((Parser *)parser, (int *)(&parser->value));
    }
}