// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 12/12)
// pure3d::BlendFrameController::vfunc_29 @ 0x00286300
// pure3d::BlendFrameController::vfunc_29 @ 0x00286300: pops the first blended entry, shifting the rest down
struct Ref_286300 {
    virtual void AddRef();
    virtual void Release();
};

struct Blend_286300 {
    int fields[9];
    char flag;
    char pad25[3];
    Ref_286300 *source;
};

namespace pure3d {
class BlendFrameController {
public:
    virtual void v0();
    char pad04[0x24];
    unsigned int count;
    Blend_286300 blends[1];
    virtual void vfunc_29();
};
}

void pure3d::BlendFrameController::vfunc_29()
{
    for (unsigned int i = 1; i < count; i++) {
        Blend_286300 &dst = blends[i - 1];
        Blend_286300 &src = blends[i];
        Ref_286300 *incoming = src.source;
        if (incoming)
            incoming->AddRef();
        if (dst.source)
            dst.source->Release();
        dst.source = incoming;
        for (int k = 0; k < 9; k++)
            dst.fields[k] = src.fields[k];
        dst.flag = src.flag;
    }
    if (count != 0) {
        count = count - 1;
        Blend_286300 &last = blends[count];
        if (last.source)
            last.source->Release();
        last.source = 0;
    }
}
