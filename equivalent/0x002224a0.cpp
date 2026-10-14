// STATUS: equivalent (tools/equiv.py level 3: 683 inputs, branch coverage 14/14)
// FUN_002224a0 @ 0x002224a0
struct BitSet {
    unsigned int count;
    unsigned int words[1];
};

struct BitSource {
    char pad00[0x10];
    BitSet *bits;            // 0x10
    unsigned int total;      // not used here
};

class BitRange {
public:
    char pad00[0x10];
    BitSource *owner;        // 0x10
    BitSource *source;       // 0x14
    unsigned int first;      // 0x18
    unsigned int last;       // 0x1c
    void FUN_002224a0(BitSource *src);
};

// Finds the first and last set bits of the source's bit set.
void BitRange::FUN_002224a0(BitSource *src) {
    if (src == 0) {
        source = 0;
        first = 0;
        last = *(unsigned int *)((char *)owner + 0x10) - 1;
        return;
    }
    source = src;
    BitSet *b = src->bits;
    unsigned int count = b->count;
    for (unsigned int i = 0; i < count; i++) {
        if (b->words[i >> 5] & (1u << (i & 31))) {
            first = i;
            break;
        }
    }
    for (unsigned int i = count - 1; i >= first; i--) {
        if (b->words[i >> 5] & (1u << (i & 31))) {
            last = i;
            break;
        }
    }
}
