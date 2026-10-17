// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000fb690 @ 0x000fb690
void __cdecl FUN_000fb690(unsigned short *destination, const unsigned short *source, int capacity)
{
    if (*source != 0) {
        int index = 0;
        while (index != capacity - 1) {
            destination[index] = source[index];
            ++index;
            if (source[index] == 0)
                break;
        }
        destination[index] = 0;
    } else {
        *destination = 0;
    }
}