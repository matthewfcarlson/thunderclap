struct Block {
    unsigned size;
    unsigned* next;
};
void __cdecl FUN_00243110(Block* b, unsigned* p, unsigned n) {
    if (!p || !n)
        return;
    unsigned count = n / b->size - 1;
    while (count) {
        *p = (unsigned)p + b->size;
        p = (unsigned*)*p;
        --count;
    }
    *p = (unsigned)b->next;
    b->next = p;
}