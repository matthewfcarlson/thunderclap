// Same code shape as 0x002e66a0 (propagated; names are from that function)
unsigned int FUN_002e66a0(unsigned int *a, unsigned int *b) {
    if (*a < *b) return 0xffffffff;
    return (unsigned int)(*b < *a);
}