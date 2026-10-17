// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001df600 @ 0x001df600
typedef void (__cdecl *Callback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void __cdecl FUN_001df600(unsigned int unused, const unsigned int *values, unsigned int unused2, Callback callback)
{
    callback(values[0], values[1], values[2], values[3], values[4]);
}