// Same code shape as 0x00221b70 (propagated; names are from that function)
typedef unsigned int u32_30f070;
struct Block_30f070 {
    u32_30f070 x[16];
};
struct Obj_30f070 {
    Block_30f070 block;
    u32_30f070 a, b, c, d, e;
    Obj_30f070* Copy(const Block_30f070* src);
};
Obj_30f070* Obj_30f070::Copy(const Block_30f070* src) {
    block = *src;
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 2;
    return this;
}