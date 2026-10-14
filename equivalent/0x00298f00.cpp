// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 12/12)
// pure3d::CompositeDrawable::vfunc_10 @ 0x00298f00
class Shader {
public:
    virtual void AddRef();
    virtual void Release();
};

class Drawable;

struct Slot_298f00 {
    char pad00[8];
    Drawable *drawable;     // 0x8
};

struct SlotList_298f00 {
    char pad00[0x3c];
    Slot_298f00 *begin;            // 0x3c
    Slot_298f00 *end;              // 0x40
};

struct Listener_298f00 {
    void FUN_00288080(Shader *shader);
};

class Drawable {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(Shader *shader);
    char pad04[0x3c];
    Shader *shader;         // 0x40
    SlotList_298f00 *slots;        // 0x44
    char pad48[4];
    Listener_298f00 *listener;     // 0x4c
};

void Drawable::vfunc_10(Shader *newShader)
{
    if (newShader != 0)
        newShader->AddRef();
    if (shader != 0)
        shader->Release();
    shader = newShader;

    if (listener != 0)
        listener->FUN_00288080(newShader);

    unsigned char count = (unsigned char)(slots->end - slots->begin);
    for (unsigned char i = 0; i < count; i++) {
        Drawable *child = slots->begin[i].drawable;
        if (child != 0)
            child->vfunc_10(shader);
    }
}
