// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::SimpleFrameController::vfunc_24 @ 0x00285830
#include "gen/pure3d.h"

struct Source_285830 {
    virtual void AddRef();
    virtual void Release();
    char pad4[0xc];
    float length;           // 0x10
};

namespace pure3d {

}
void pure3d::SimpleFrameController::vfunc_24(int __p0, int start, int unused) { Source_285830 * src = (Source_285830 *)__p0;

    if (src == 0) {
        if ((*(Source_285830 * *)&this->f_3c) != 0)
            (*(Source_285830 * *)&this->f_3c)->Release();
        (*(Source_285830 * *)&this->f_3c) = 0;
        vfunc_14(0.0f, 0.0f);
        vfunc_12(0);
        return;
    }

    src->AddRef();
    if ((*(Source_285830 * *)&this->f_3c) != 0)
        (*(Source_285830 * *)&this->f_3c)->Release();
    (*(Source_285830 * *)&this->f_3c) = src;
    float last = src->length - 1.0f;
    if (last < 0.0f)
        last = 0.0f;
    vfunc_14(0.0f, last);
    vfunc_12(start);
}
