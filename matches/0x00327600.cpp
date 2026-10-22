namespace pure3d {
struct d3dPrimBufferStream {
    virtual void vfunc_0();
    char padding[0x4c];
    unsigned int* packedNormal;
    void vfunc_11(float x, float y, float z);
};
void d3dPrimBufferStream::vfunc_11(float x, float y, float z) {
    int iy = (int)(__int64)(y * 2147418112.0f);
    int iz = (int)(__int64)(z * 2147418112.0f);
    int ix = (int)(__int64)(x * 2147418112.0f);
    *packedNormal = (((unsigned int)(__int64)(iy >> 21) & 0x7ffU) | ((unsigned int)(__int64)(iz >> 22) << 11)) << 11 |
                    ((unsigned int)(__int64)(ix >> 21) & 0x7ffU);
}
} // namespace pure3d