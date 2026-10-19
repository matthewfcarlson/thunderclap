// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0033c4d0 @ 0x0033c4d0
// equiv-conv: FUN_0033c320 eax edi
unsigned int FUN_0033c320(unsigned int value, int character);
// equiv-conv: FUN_0033c430 ebx eax stack
unsigned int FUN_0033c430(unsigned int c, const char *text, int remaining);
// equiv-conv: FUN_0033c4d0 eax ecx stack
unsigned int FUN_0033c4d0(const char *text, unsigned int character, int remaining)
{
    unsigned char c = (unsigned char)*text;
    if (c == '%')
        return FUN_0033c320(character, (signed char)text[1]);
    if (c == '.')
        return 1;
    if (c == '[')
        return FUN_0033c430(character, text, remaining - 1);
    return c == character;
}
