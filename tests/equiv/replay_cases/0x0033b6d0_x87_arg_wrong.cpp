// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0033b6d0 @ 0x0033b6d0
float __cdecl FUN_00339ec0(int value, int mode);
float __cdecl FUN_003442bc(int value, int mode);
void __cdecl FUN_00213340(int value, float amount);

int __cdecl FUN_0033b6d0(int value)
{
    FUN_00339ec0(value, 1);
    float amount = FUN_003442bc(value, 1);
    FUN_00213340(value, amount);
    return 1;
}
