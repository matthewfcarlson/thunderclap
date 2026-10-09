class Thing {
  public:
    char pad0[4];
    unsigned int divisor;
    char pad8[8];
    unsigned int base;
    unsigned int* bits;
    unsigned int limit;
    void Clear(int value, int unused);
};

void Thing::Clear(int value, int unused) {
    unsigned int index = (value - base) / divisor;
    bits[index >> 5] &= ~(1u << (index & 31));
    if (index < limit)
        limit = index;
}