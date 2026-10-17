// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_00212fe0 @ 0x00212fe0
// equiv-conv: FUN_00212bb0 ecx edx
int* FUN_00212bb0(int first, int second);
int __cdecl FUN_00212fe0(int second, int first)
{
    int value = *FUN_00212bb0(first, second);
    return value == 7 || value == 2;
}
