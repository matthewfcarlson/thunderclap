#include "gen/pure3d.h"

struct Device_333110 {
    char pad[0x110];
    int pixelShader;
};
void __stdcall D3DDevice_SetPixelShader(unsigned int);

void pure3d::d3dBumpMapVertexShader::vfunc_13() {
    Device_333110* d = (*(Device_333110 * *)&this->f_14);
    if (d->pixelShader) {
        d->pixelShader = 0;
        D3DDevice_SetPixelShader(0);
    }
}
