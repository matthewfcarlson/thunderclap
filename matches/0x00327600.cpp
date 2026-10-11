namespace pure3d {
struct d3dPrimBufferStream {
    virtual void vfunc_0();
    char padding[0x4c];
    unsigned int* packedNormal;
    void vfunc_11(float x, float y, float z);
};
void d3dPrimBufferStream::vfunc_11(float x, float y, float z) {
    int iy = (int)(y * 2147418112.0f);
    int iz = (int)(z * 2147418112.0f);
    int ix = (int)(x * 2147418112.0f);
    *packedNormal = (((unsigned int)(iy >> 21) & 0x7ffU) | ((unsigned int)(iz >> 22) << 11)) << 11 |
                    ((unsigned int)(ix >> 21) & 0x7ffU);
}
} // namespace pure3d