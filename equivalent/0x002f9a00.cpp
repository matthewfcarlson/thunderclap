// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 9/10, incomplete)
// FUN_002f9a00 @ 0x002f9a00
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);

struct WideVector {
    unsigned short* first;
    unsigned short* last;
    unsigned short* cap;
    WideVector* FUN_002f9a00(const WideVector* other);
};

WideVector* WideVector::FUN_002f9a00(const WideVector* other) {
    int capacity = other->cap - other->first;
    if (capacity != 0) {
        first = (unsigned short*)FUN_0008d6d0(capacity * 2);
        if (first) {
            last = first;
            cap = first + capacity;
            const unsigned short* src = other->first;
            unsigned short* dst = first;
            for (int n = other->last - other->first; n != 0; n--) {
                if (dst)
                    *dst = *src;
                src++;
                dst++;
            }
            last = dst;
            return this;
        }
    } else {
        first = 0;
    }
    last = 0;
    cap = 0;
    return this;
}
