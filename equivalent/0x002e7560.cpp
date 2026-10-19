// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e7560 @ 0x002e7560
typedef unsigned char byte;
// png_get_uint_16: the result is ax (the original's `movzx ax, ...` leaves eax's upper half as it was)
unsigned short __cdecl FUN_002e7560(const byte *data)
{
    return (unsigned short)((data[0] << 8) + data[1]);
}
