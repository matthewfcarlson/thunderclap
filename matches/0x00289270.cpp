struct Key {
    unsigned pad[2];
    unsigned lo;
    unsigned hi;
};
int FUN_00289270(Key** a, Key** b) {
    Key* x = *a;
    Key* y = *b;
    unsigned blo = y->lo;
    unsigned bhi = y->hi;
    unsigned alo = x->lo;
    unsigned ahi = x->hi;
    if (ahi <= bhi) {
        if (ahi < bhi || alo < blo)
            return -1;
    }
    if (ahi < bhi || (ahi <= bhi && alo <= blo))
        return 0;
    return 1;
}