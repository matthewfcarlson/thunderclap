extern int ImageVtable;
struct Ctor_0027b070 {
    Ctor_0027b070();
};
class Sub_2bfb20 {
  public:
    void Copy(const Sub_2bfb20*);
};
struct Image : public Ctor_0027b070 {
    int* vt;
    char pad4[0x0c];
    int m10;
    int m14;
    char pad18[4];
    int m1c;
    int m20;
    int m24;
    char pad28;
    unsigned char m29;
    Image(const Image*);
};
Image::Image(const Image* src) : Ctor_0027b070() {
    vt = &ImageVtable;
    if (src)
        ((Sub_2bfb20*)((char*)this + 8))->Copy((const Sub_2bfb20*)((const char*)src + 8));
    m24 = 0;
    m20 = src->m20;
    m1c = src->m1c;
    m29 = src->m29;
    m10 = src->m10;
    m14 = src->m14;
}
