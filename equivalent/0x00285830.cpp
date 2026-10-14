// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::SimpleFrameController::vfunc_24 @ 0x00285830
struct Source_285830 {
    virtual void AddRef();
    virtual void Release();
    char pad4[0xc];
    float length;           // 0x10
};

namespace pure3d {
class SimpleFrameController {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void SetStart(int start);                     // slot 12
    virtual void v13();
    virtual void SetRange(float lo, float hi);            // slot 14
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23();
    virtual void vfunc_24(Source_285830 *source, int start, int unused);

    char pad4[0x38];
    Source_285830 *source;         // 0x3c
};

void SimpleFrameController::vfunc_24(Source_285830 *src, int start, int unused)
{
    if (src == 0) {
        if (source != 0)
            source->Release();
        source = 0;
        SetRange(0.0f, 0.0f);
        SetStart(0);
        return;
    }

    src->AddRef();
    if (source != 0)
        source->Release();
    source = src;
    float last = src->length - 1.0f;
    if (last < 0.0f)
        last = 0.0f;
    SetRange(0.0f, last);
    SetStart(start);
}
}
