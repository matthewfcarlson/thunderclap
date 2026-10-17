// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00270980 @ 0x00270980
// equiv-conv: FUN_00270980 eax
extern "C" int __cdecl FUN_00345b90(int ch);
void FUN_00270980(char* text) {
    while (*text) {
        *text = (char)FUN_00345b90(*text);
        ++text;
    }
}