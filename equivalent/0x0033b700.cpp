// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_0033b700 @ 0x0033b700
// FUN_0033b700 @ 0x0033b700
float __cdecl FUN_00339ec0(int, int);
extern "C" double __cdecl acos(double);
void __cdecl FUN_00213340(int, float);
int __cdecl FUN_0033b700(int value) {
    float a = FUN_00339ec0(value, 1);
    float b = (float)acos(a);
    FUN_00213340(value, b);
    return 1;
}
