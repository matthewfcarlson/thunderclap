// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00085e60 @ 0x00085e60
extern float DAT_003ffaa4;

double __cdecl FUN_00085e60(unsigned int low, unsigned int high)
{
    unsigned __int64 bits = ((unsigned __int64)high << 32) | low;
    return (double)bits * DAT_003ffaa4;
}
