// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0025be60 @ 0x0025be60
void __cdecl FUN_0025be60(unsigned int *source, unsigned int *destination)
{
    unsigned int value = *source;
    *destination = value;
    if ((*source & 15) == 4)
        *destination = value & ~15u;
}
