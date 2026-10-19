// STATUS: equivalent (tools/equiv.py level 3: 18536 inputs, branch coverage 0/0)
// FUN_00214a90 @ 0x00214a90
// FUN_00214a90 @ 0x00214a90
int __cdecl FUN_002160c0(int, int, void*);
// equiv-conv: FUN_00214900 ebx stack
void __cdecl FUN_00214900(int, int);
void __cdecl FUN_002149b0(int);
void __cdecl FUN_00214a90(int first, int second, int third)
{
    int result = FUN_002160c0(first, second, &third);
    FUN_00214900(first, result);
    FUN_002149b0(first);
}
