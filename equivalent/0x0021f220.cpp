// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 6/6)
// FUN_0021f220 @ 0x0021f220
struct Parser { char pad0[12]; int character; char pad1[12]; int value; }; // equiv-conv: FUN_0021f220 ecx eax
// equiv-conv: FUN_0021c3d0 ecx eax
int FUN_0021c3d0(Parser *parser, int input);
void __cdecl FUN_0021c790(int value, int token, int input, int flag);
// equiv-conv: FUN_0021ccb0 eax
void FUN_0021ccb0(Parser *parser);
// equiv-conv: FUN_0021f220 ecx eax
int FUN_0021f220(Parser *parser, int input)
{
    int token = FUN_0021c3d0(parser, input);
    FUN_0021c790(parser->value, token, input, 1);
    while (parser->character == 0x2e)
        FUN_0021ccb0(parser);
    if (parser->character == 0x3a) {
        FUN_0021ccb0(parser);
        return 1;
    }
    return 0;
}