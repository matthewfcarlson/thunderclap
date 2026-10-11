// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 9/10, incomplete)
// FUN_00271820 @ 0x00271820
extern const unsigned short DAT_004cdb08[];
unsigned int __cdecl FUN_002716c0(const unsigned char *text, unsigned int *length, unsigned int *value);

unsigned int __cdecl FUN_00271820(const unsigned char *text, unsigned int *length, unsigned int *value)
{
    unsigned int character = *text;
    if (character < 0x80)
        return FUN_002716c0(text, length, value);

    if (character <= 0x9f)
        character = DAT_004cdb08[character];

    if (length)
        *length = 1;
    if (value)
        *value = character;
    return ((unsigned int)value & 0xffffff00u) | 1;
}
