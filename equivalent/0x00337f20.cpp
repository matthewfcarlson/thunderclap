// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 13/13)
// FUN_00337f20 @ 0x00337f20
unsigned int __cdecl FUN_00337f20(unsigned int value)
{
    switch (value) {
    case 0: return 1;
    case 1: case 2: case 3: case 4: case 9: case 10: return 4;
    case 5: case 7: return 8;
    case 6: case 8: return 12;
    default: return 0;
    }
}