typedef unsigned char u8;
extern "C" void* memset(void*, int, unsigned int);
class Image8 {
  public:
    char pad[0x10];
    int width;
    int height;
    char pad2[0x0c];
    u8* pixels;
    void vfunc_11(int value);
};
void Image8::vfunc_11(int value) {
    memset(pixels, value, width * height);
}
