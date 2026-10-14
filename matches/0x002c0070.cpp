typedef unsigned int u32_2c0070;
void thunk_FUN_00267090(void*);
void* FUN_0008d6d0(u32_2c0070);
class Image32 {
  public:
    char pad0[0x10];
    int width;
    int height;
    char pad18[0x0c];
    void* pixels;
    void vfunc_5(int, int);
};
void Image32::vfunc_5(int w, int h) {
    width = w;
    height = h;
    thunk_FUN_00267090(pixels);
    pixels = FUN_0008d6d0(height * width * 4);
}