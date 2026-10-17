// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00337e50 @ 0x00337e50
typedef unsigned char byte;
byte __cdecl FUN_00337e50(const char *text) {
    const char *expected = "true";
    for (int i = 0; i < 5; ++i) {
        if (text[i] != expected[i]) return 0;
    }
    return 1;
}