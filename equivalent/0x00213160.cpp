// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00213160 @ 0x00213160
// equiv-conv: FUN_00212bb0 edx ecx
int* FUN_00212bb0(int first, int second);

int __cdecl FUN_00213160(int first, int second)
{
    int* result = FUN_00212bb0(first, second);
    return result[0] != 0 && (result[0] != 1 || result[1] != 0);
}
