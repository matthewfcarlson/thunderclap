// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 14/14)
// FUN_002716f0 @ 0x002716f0
extern int __cdecl FUN_002716f0(unsigned int character, char *output, unsigned int capacity, unsigned int fallback, unsigned int *written, unsigned int state);

int __cdecl convertCharacter(unsigned int character, char *output, unsigned int capacity, unsigned int fallback, unsigned int *written, unsigned int state)
{
    if (capacity == 0)
        return -1;
    if (character <= 0x7f) {
        *output = (char)character;
        *written = 1;
        return 0;
    }
    if (character >= 0xff01 && character <= 0xff5e) {
        *output = (char)(character + 0x20);
        *written = 1;
        return 0;
    }
    if (character == 0x3000) {
        *output = ' ';
        *written = 1;
        return 0;
    }
    if (fallback == 0)
        return -4;
    int result = FUN_002716f0(fallback, output, capacity, 0, written, state);
    return result == -2 ? -6 : result;
}
