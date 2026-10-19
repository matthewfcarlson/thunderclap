// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 4/4)
// FUN_00213260 @ 0x00213260
// FUN_00213260 @ 0x00213260
struct Result { int kind; int value; };
Result* __fastcall FUN_00212bb0(int second, int first);
int __cdecl FUN_00213260(int first, int second) {
    Result* result = FUN_00212bb0(second, first);
    if (result->kind == 2) return result->value;
    if (result->kind == 7) return result->value + 16;
    return 0;
}
