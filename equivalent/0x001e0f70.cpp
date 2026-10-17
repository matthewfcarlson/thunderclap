// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001e0f70 @ 0x001e0f70
typedef void (__stdcall *Callback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void __cdecl FUN_001e0f70(unsigned int unused, const unsigned int *values, unsigned int unused2, Callback callback)
{
    callback(values[0], values[1], values[2], values[3], values[4], values[5]);
}