// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0025c7c0 @ 0x0025c7c0
extern "C" int __cdecl FUN_0025abd0(void*, unsigned int*);

int __cdecl FUN_0025c7c0(void* source, unsigned int* destination)
{
    unsigned int value;
    int result = 0;
    for (unsigned int row = 0; row < 64; row += 4) {
        for (unsigned int column = 0; column < 4; ++column) {
            result = FUN_0025abd0(source, &value);
            if (!(result & 255)) return result & ~255;
            destination[row + column] = value;
        }
    }
    return (result & ~255) | 1;
}