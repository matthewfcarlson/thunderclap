// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_00212fe0 @ 0x00212fe0
// FUN_00212fe0 @ 0x00212fe0
int* __fastcall FUN_00212bb0(int first, int second);
int __cdecl FUN_00212fe0(int second, int first)
{
    int value = *FUN_00212bb0(first, second);
    return value == 7 || value == 2;
}
