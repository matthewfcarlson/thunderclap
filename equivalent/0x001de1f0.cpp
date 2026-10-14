// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 17/18, incomplete)
// FUN_001de1f0 @ 0x001de1f0
struct Elem_1de1f0 {
    int a;
    int b;
    int c;
    int d;
    short e;
    short f;
};

// std::rotate(first, middle, last) for 20-byte elements (gcd-cycle algorithm).
void __cdecl FUN_001de1f0(Elem_1de1f0 *first, Elem_1de1f0 *middle, Elem_1de1f0 *last)
{
    int shift = (int)((char *)middle - (char *)first) / 20;
    int total = (int)((char *)last - (char *)first) / 20;
    int count = total;
    for (int factor = shift; factor != 0; ) {
        int rest = count % factor;
        count = factor;
        factor = rest;
    }
    if (count < total && count > 0) {
        for (; count > 0; --count) {
            Elem_1de1f0 *hole = first + count;
            Elem_1de1f0 *next = hole;
            Elem_1de1f0 holeVal = *hole;
            Elem_1de1f0 *next1 = hole + shift;
            if (next1 == last)
                next1 = first;
            while (next1 != hole) {
                *next = *next1;
                next = next1;
                int left = (int)((char *)last - (char *)next1) / 20;
                if (shift < left)
                    next1 = next1 + shift;
                else
                    next1 = first + (shift - left);
            }
            *next = holeVal;
        }
    }
}
