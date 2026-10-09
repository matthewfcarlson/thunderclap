extern "C" void* __stdcall D3DPalette_Lock2(void*, int);
extern "C" void* memcpy(void*, const void*, unsigned int);
namespace pure3d {
struct d3dTexture {
    char pad[0x68];
    void* palette;
    void vfunc_11(unsigned int, unsigned int*);
};
} // namespace pure3d
void pure3d::d3dTexture::vfunc_11(unsigned int count, unsigned int* src) {
    if (palette) {
        void* dst = D3DPalette_Lock2(palette, 0);
        volatile unsigned int* p = src;
        memcpy(dst, (const void*)p, count * 4);
    }
}