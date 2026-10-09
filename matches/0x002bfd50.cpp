class Image8 {
  public:
    char pad0[0x10];
    int stride;
    char pad14[0x0c];
    unsigned char pad20[4];
    unsigned char* pixels;
    void vfunc_19(int x, int y, unsigned char value);
};
void Image8::vfunc_19(int x, int y, unsigned char value) {
    pixels[stride * y + x] = value;
}