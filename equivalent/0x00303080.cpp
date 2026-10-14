// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 17/18, incomplete)
// FUN_00303080 @ 0x00303080
struct Elem_303080 {
    unsigned int w[17];
};

// std::rotate for 0x44-byte elements (Dinkumware _Rotate, random access).
void FUN_00303080(Elem_303080* first, Elem_303080* mid, Elem_303080* last)
{
    int shift = mid - first;
    int total = last - first;
    int cycles = total;
    int factor = shift;
    while (factor != 0) {
        int tmp = cycles % factor;
        cycles = factor;
        factor = tmp;
    }
    if (cycles < total) {
        for (; cycles > 0; cycles--) {
            Elem_303080* hole = first + cycles;
            Elem_303080* next = hole;
            Elem_303080 holeVal = *hole;
            Elem_303080* next1;
            if (next + shift == last)
                next1 = first;
            else
                next1 = next + shift;
            while (next1 != hole) {
                *next = *next1;
                next = next1;
                if (last - next1 > shift)
                    next1 = next1 + shift;
                else
                    next1 = first + (shift - (last - next1));
            }
            *next = holeVal;
        }
    }
}
