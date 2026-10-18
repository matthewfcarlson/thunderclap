// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00011000 @ 0x00011000
// FUN_00011000 @ 0x00011000
extern "C" double __cdecl acos(double);
float __cdecl FUN_00011000(float value)
{
    double result = acos(value);
    return (float)result;
}
