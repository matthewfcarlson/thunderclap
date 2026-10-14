// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 9/10, incomplete)
// FUN_002a4760 @ 0x002a4760
void *FUN_0008d6d0(unsigned int size);

struct IntVector {
    int *first;
    int *last;
    IntVector(const IntVector &other) throw();
};

IntVector::IntVector(const IntVector &other) throw()
{
    int count = other.last - other.first;
    if (count != 0) {
        first = (int *)FUN_0008d6d0(count * 4);
        if (first != 0) {
            last = first + count;
            int *dst = first;
            const int *src = other.first;
            for (count = other.last - src; count != 0; count--) {
                if (dst != 0)
                    *dst = *src;
                src++;
                dst++;
            }
            return;
        }
    }
    first = 0;
    last = 0;
}
