// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 17/18, incomplete)
// FUN_002f3b10 @ 0x002f3b10
// std::rotate for a range of 2-byte elements (cycle-leader algorithm)
void FUN_002f3b10(short *first, short *middle, short *last)
{
    int shift = (int)(middle - first);
    int total = (int)(last - first);
    int cycles = total;
    for (int factor = shift; factor != 0;) {
        int rem = cycles % factor;
        cycles = factor;
        factor = rem;
    }
    if (cycles < total) {
        for (; cycles > 0; --cycles) {
            short *hole = first + cycles;
            short *next = hole;
            short holeValue = *hole;
            short *next1 = (next + shift == last) ? first : next + shift;
            while (next1 != hole) {
                *next = *next1;
                next = next1;
                int left = (int)(last - next1);
                next1 = (shift < left) ? next1 + shift : first + (shift - left);
            }
            *next = holeValue;
        }
    }
}
