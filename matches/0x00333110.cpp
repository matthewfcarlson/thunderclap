struct Device_333110 {
    char pad[0x110];
    int pixelShader;
};
struct pure3d_d3dBumpMapVertexShader_333110 {
    char pad[0x14];
    Device_333110* device;
    void vfunc_13();
};
void __stdcall D3DDevice_SetPixelShader(unsigned int);
void pure3d_d3dBumpMapVertexShader_333110::vfunc_13() {
    Device_333110* d = device;
    if (d->pixelShader) {
        d->pixelShader = 0;
        D3DDevice_SetPixelShader(0);
    }
}