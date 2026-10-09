struct Block { unsigned int a,b,c,d; };
void Copy(Block* src, int count, Block* dst) {
    Block* d = dst;
    while (count != 0) {
        if (d != 0) {
            Block x = *src;
            *d = x;
        }
        ++src; ++d; --count;
    }
}
