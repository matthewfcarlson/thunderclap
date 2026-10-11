struct Image {
    unsigned int width;
    unsigned int p4;
    unsigned int pad;
    unsigned int rowbytes;
    char pad2[8];
    char channels;
    unsigned char type;
    unsigned char b8;
    unsigned char b9;
    unsigned char b7;
    unsigned char row;
    unsigned char bits;
};
extern void Report(int, const char*);
void FUN_002eb240(int a, Image* p, unsigned int width, unsigned int p4, char channels, unsigned char type,
                  unsigned char b7, unsigned char b8, unsigned char b9) {
    if (!a || !p)
        return;
    p->width = width;
    p->channels = channels;
    p->p4 = p4;
    p->b8 = b8;
    p->type = type;
    p->b9 = b9;
    p->b7 = b7;
    if (type == 3 || (type & 2) == 0)
        p->row = 1;
    else
        p->row = 3;
    if (type & 4)
        ++p->row;
    unsigned char bits = p->row * channels;
    p->bits = bits;
    unsigned int divisor = (bits + 7) >> 3;
    if (width > 0x7fffffff / divisor) {
        Report(a, "Width too large to process image data; rowbytes will overflow.");
        p->rowbytes = 0;
        return;
    }
    p->rowbytes = (bits * width + 7) >> 3;
}
