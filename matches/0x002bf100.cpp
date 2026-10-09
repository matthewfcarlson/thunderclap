typedef unsigned int u32;
extern void BaseInit();
struct ImageFont {
    volatile u32 vt;
    char pad[12];
    volatile u32 a, b, c, d, e;
    volatile int f;
    volatile u32 g, h, i, j;
    ImageFont();
};
ImageFont::ImageFont() {
    BaseInit();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    vt = 0x42e9bc;
    f = -1;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
}
