// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00011010 @ 0x00011010
// FUN_00011010 @ 0x00011010
extern "C" double __cdecl asin(double);
float __cdecl FUN_00011010(float value) {
    double result = asin(value);
    return (float)result;
}
