// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 4/4)
// FUN_0021c3d0 @ 0x0021c3d0
struct Parser { char pad0[4]; int current; int previous; int type; int value; int nextType; int nextValue; };
void __cdecl FUN_0021b060(Parser*, const char*);
int __cdecl FUN_0021bbc0(Parser*, int*);
// equiv-conv: FUN_0021c3d0 esi
int FUN_0021c3d0(Parser* parser)
{
    if (parser->type != 0x116)
        FUN_0021b060(parser, "<name> expected");
    parser->previous = parser->current;
    int result = parser->value;
    if (parser->nextType != 0x11f) {
        parser->value = parser->nextValue;
        parser->type = parser->nextType;
        parser->nextType = 0x11f;
    } else {
        parser->type = FUN_0021bbc0(parser, &parser->value);
    }
    return result;
}