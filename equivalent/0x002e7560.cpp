// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e7560 @ 0x002e7560
typedef unsigned char byte;
// equiv-conv: FUN_002e7560 eax stack
unsigned int __cdecl FUN_002e7560(unsigned int incomingEax, const byte *data)
{
    unsigned int upper = (incomingEax & 0xffff0000u) << 8;
    return upper + ((unsigned int)data & 0xffff0000u) + ((unsigned int)data[0] << 8) + data[1];
}
