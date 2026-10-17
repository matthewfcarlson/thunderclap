// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009ae00 @ 0x0009ae00
typedef void (__stdcall *Callback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void __cdecl FUN_0009ae00(unsigned int unused, const unsigned char *data, unsigned int unused2, Callback callback)
{
    unsigned int first = 0x5a5a5a00u | data[0];
    unsigned int second = 0x5a5a5a00u | data[4];
    unsigned int third = ((unsigned int)data & 0xffffff00u) | data[8];
    callback(first, second, third, data[12], *(const unsigned int *)(data + 16));
}