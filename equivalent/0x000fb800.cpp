// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000fb800 @ 0x000fb800
typedef unsigned short wchar16;
// equiv-conv: FUN_000fb800 ecx edx
bool __fastcall FUN_000fb800(const wchar16* text, wchar16 value) {
    while (*text) {
        if (*text == value) return true;
        ++text;
    }
    return false;
}