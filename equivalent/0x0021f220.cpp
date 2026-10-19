// STATUS: equivalent (tools/equiv.py level 3: 15585 inputs, branch coverage 6/6)
// FUN_0021f220 @ 0x0021f220
// FUN_0021f220 @ 0x0021f220
struct Parser { char pad0[12]; int character; char pad1[12]; int value; }; // equiv-conv: FUN_0021f220 ecx eax
// equiv-conv: FUN_0021c3d0 esi
int FUN_0021c3d0(Parser *parser);
void __cdecl FUN_0021c790(int value, int token, int input, int flag);
// equiv-conv: FUN_0021ccb0 eax ebx
void FUN_0021ccb0(Parser *parser, int input);
// equiv-conv: FUN_0021f220 ecx eax
int FUN_0021f220(Parser *parser, int input)
{
    int token = FUN_0021c3d0(parser);
    FUN_0021c790(parser->value, token, input, 1);
    while (parser->character == 0x2e)
        FUN_0021ccb0(parser, input);
    if (parser->character == 0x3a) {
        FUN_0021ccb0(parser, input);
        return 1;
    }
    return 0;
}
