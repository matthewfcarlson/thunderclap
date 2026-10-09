struct Device {
    char pad[0x110];
    int pixelShader;
};
struct pure3d_d3dBumpMapVertexShader {
    char pad[0x14];
    Device* device;
    void vfunc_13();
};
void __stdcall D3DDevice_SetPixelShader(unsigned int);
void pure3d_d3dBumpMapVertexShader::vfunc_13() {
    Device* d = device;
    if (d->pixelShader) {
        d->pixelShader = 0;
        D3DDevice_SetPixelShader(0);
    }
}