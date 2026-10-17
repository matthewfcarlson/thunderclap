// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00261680 @ 0x00261680
extern "C" void* __cdecl FUN_002611b0(void* value);
extern "C" float __cdecl FUN_00260d00(void* value);
extern "C" char DAT_004269b4[];
extern "C" char DAT_00429b50[];

const char* __cdecl FUN_00261680(void* value)
{
    void* first = FUN_002611b0(value);
    void* second = FUN_002611b0(value);
    float firstValue = FUN_00260d00(first);
    float secondValue = FUN_00260d00(second);
    return secondValue > firstValue ? DAT_00429b50 : DAT_004269b4;
}