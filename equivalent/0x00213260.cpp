// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// FUN_00213260 @ 0x00213260
struct Result { int kind; int value; };
// equiv-conv: FUN_00212bb0 edx ecx
Result* FUN_00212bb0(int first, int second);
int __cdecl FUN_00213260(int first, int second) {
    Result* result = FUN_00212bb0(first, second);
    if (result->kind == 2) return result->value;
    if (result->kind == 7) return result->value + 16;
    return 0;
}