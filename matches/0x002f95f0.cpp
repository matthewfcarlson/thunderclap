struct Block_2f95f0 {
    unsigned int a, b, c, d;
};
Block_2f95f0* Copy(Block_2f95f0* src, int count, Block_2f95f0* dst) {
    Block_2f95f0* d = dst;
    while (count != 0) {
        if (d != 0) {
            Block_2f95f0 x = *src;
            *d = x;
        }
        ++src;
        ++d;
        --count;
    }
    return d;
}
