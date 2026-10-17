// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001e0970 @ 0x001e0970
typedef unsigned char (__stdcall *Callback)(unsigned char *, unsigned int, unsigned int, unsigned int);
void __cdecl FUN_001e0970(unsigned int unused, unsigned int *values, unsigned char *output, Callback callback)
{
    unsigned char result = callback((unsigned char *)values[0], values[1], values[2], values[3]);
    if (output != 0)
        *output = result;
}
