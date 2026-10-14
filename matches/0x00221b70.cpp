typedef unsigned int u32_221b70;
struct Block_221b70 {
    u32_221b70 x[16];
};
struct Obj_221b70 {
    Block_221b70 block;
    u32_221b70 a, b, c, d, e;
    void Copy(const Block_221b70* src);
};
void Obj_221b70::Copy(const Block_221b70* src) {
    block = *src;
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 2;
}