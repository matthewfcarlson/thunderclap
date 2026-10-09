typedef unsigned int u32;
struct Partition { u32 vptr; u32 pad; u32 a; u32 b; u32 c; u32 pad2; };
struct Source { char pad[8]; u32 a; u32 b; u32 c; };
Partition* f(Partition* out, int count, Source* src) {
    while (count != 0) {
        if (out) {
            out->vptr = 0x42c1b4;
            out->a = src->a;
            out->b = src->b;
            out->c = src->c;
        }
        out = (Partition*)((char*)out + 0x18);
        --count;
    }
    return out;
}