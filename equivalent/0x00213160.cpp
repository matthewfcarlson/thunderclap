// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 6/6)
// FUN_00213160 @ 0x00213160
// FUN_00213160 @ 0x00213160
int* __fastcall FUN_00212bb0(int second, int first);

int __cdecl FUN_00213160(int first, int second)
{
    int* result = FUN_00212bb0(second, first);
    return result[0] != 0 && (result[0] != 1 || result[1] != 0);
}
