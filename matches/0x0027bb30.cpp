extern "C" char DAT_0042c1b4[];
typedef unsigned int u32_27bb30;
struct Partition {
    u32_27bb30 vptr;
    u32_27bb30 pad;
    u32_27bb30 a;
    u32_27bb30 b;
    u32_27bb30 c;
    u32_27bb30 pad2;
};
struct Source_27bb30 {
    char pad[8];
    u32_27bb30 a;
    u32_27bb30 b;
    u32_27bb30 c;
};
Partition* f(Partition* out, int count, Source_27bb30* src) {
    while (count != 0) {
        if (out) {
            out->vptr = ((int)DAT_0042c1b4);
            out->a = src->a;
            out->b = src->b;
            out->c = src->c;
        }
        out = (Partition*)((char*)out + 0x18);
        --count;
    }
    return out;
}