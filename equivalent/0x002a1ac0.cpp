// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 17/18, incomplete)
// FUN_002a1ac0 @ 0x002a1ac0
// std::rotate for a range of 4-byte elements (cycle-leader algorithm)
void FUN_002a1ac0(int *first, int *middle, int *last)
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
            int *hole = first + cycles;
            int *next = hole;
            int holeValue = *hole;
            int *next1 = (next + shift == last) ? first : next + shift;
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
