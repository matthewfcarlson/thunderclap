typedef unsigned char u8_2d95c0;
struct X_2d95c0 {
    int n;
    int count;
    char a;
    unsigned char mode;
    unsigned char width;
    unsigned char bits;
};
void FUN_002d95c0(X_2d95c0* p, u8_2d95c0* src) {
    if (p->mode == 0x10) {
        unsigned int i = (unsigned int)p->width * (unsigned int)p->n;
        u8_2d95c0* in = src;
        u8_2d95c0* out = src;
        while (i > 0) {
            *out = *in;
            in += 2;
            ++out;
            --i;
        }
        p->mode = 8;
        p->bits = p->width << 3;
        p->count = (int)p->width * p->n;
    }
}