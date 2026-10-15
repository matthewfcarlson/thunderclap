struct Block {
    int a, b, c, d;
};
Block* FUN_002f9460(Block* first, Block* last, Block* dst) {
    for (; first != last; ++first, ++dst)
        *dst = *first;
    return dst;
}