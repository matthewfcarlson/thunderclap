// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00011010 @ 0x00011010
extern float FUN_003442bc();
float __cdecl FUN_00011010(float value) {
    float result = FUN_003442bc();
    volatile float dummy = value;
    return result;
}
