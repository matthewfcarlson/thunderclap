// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009a7a0 @ 0x0009a7a0
typedef void (__stdcall *Callback)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
void __cdecl FUN_0009a7a0(unsigned unused, const unsigned *values, unsigned unused2, Callback callback)
{
    callback(values[0], values[1], values[2], values[3], values[4], values[5]);
}
