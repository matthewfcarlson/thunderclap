extern "C" void* memcpy(void*, const void*, unsigned);
struct Info {
    char p[0x10];
    int count;
    int p14;
    int bpp;
};
class IB {
  public:
    virtual void v0();
    virtual void v1();
    virtual void Put(const unsigned char* src);
    Info* info;
    unsigned* pal;
    unsigned char* dst;
    int idx;
    int stride;
};
void IB::Put(const unsigned char* src) {
    int n;
    if (info->bpp == 8) {
        n = info->count;
        memcpy(dst, src, n);
    } else {
        n = info->count;
        for (int i = 0; i < n; i++)
            ((unsigned*)dst)[i] = pal[src[i]];
    }
    dst += stride;
    idx++;
}
