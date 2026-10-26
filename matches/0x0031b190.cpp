#include "gen/pure3d.h"
#include "decls/data/platform/xbox/pure3d.h"

namespace D3D8 {
void D3D_KickOffAndWaitForIdle();
void D3DDevice_BlockUntilVerticalBlank();
void __stdcall D3DDevice_Swap(int);
} // namespace D3D8

void pure3d::d3dDisplay::vfunc_14() {
    D3D8::D3D_KickOffAndWaitForIdle();
    unsigned char c = (*(unsigned char*)&DAT_005554a0);
    int n = (*(int*)&DAT_0055549c);
    bool wait = true;
    if (c == 0) {
        if (n == 0)
            D3D8::D3DDevice_BlockUntilVerticalBlank();
        else if (n != 1)
            wait = false;
    }
    if (wait)
        D3D8::D3DDevice_BlockUntilVerticalBlank();
    (*(int*)&DAT_0055549c) = 0;
    this->f_434 = 0;
    D3D8::D3DDevice_Swap(0);
    D3D8::D3D_KickOffAndWaitForIdle();
}
