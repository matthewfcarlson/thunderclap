typedef unsigned int u32;
struct Block {
    u32 x[16];
};
struct Obj {
    Block block;
    u32 a, b, c, d, e;
    void Copy(const Block* src);
};
void Obj::Copy(const Block* src) {
    block = *src;
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 2;
}