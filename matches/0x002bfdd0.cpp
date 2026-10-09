struct Image8 {
    char pad0[0x10];
    int width;
    int height;
    char pad18[0x0c];
    void* pixels;
    void vfunc_5(int, int);
};
void __cdecl free_pixels(void*);
void* __cdecl alloc_pixels(int);
void Image8::vfunc_5(int w, int h) {
    width = w;
    height = h;
    free_pixels(pixels);
    pixels = alloc_pixels(height * width);
}