// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00212f70 @ 0x00212f70
struct Result { int value; };
Result* __fastcall FUN_00212bb0(void* first, void* second);
int __cdecl FUN_00217600(Result* result, void* scratch);
int __cdecl FUN_00212f70(void* first, void* second) {
    char scratch[8];
    Result* result = FUN_00212bb0(second, first);
    if (result->value != 3 && FUN_00217600(result, scratch) == 0)
        return 0;
    return 1;
}