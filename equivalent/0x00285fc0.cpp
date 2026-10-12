// STATUS: equivalent (tools/equiv.py level 3: 638 inputs, branch coverage 30/30)
// pure3d::BlendFrameController::vfunc_24 @ 0x00285fc0
struct RefObj {
    virtual void AddRef();
    virtual void Release();
    char pad04[0xc];
    float length;
};

struct Track {
    float cur;
    int a4;
    int a8;
    float remain;
    float fadeRate;
    float weight;
    int f18;
    int f1c;
    int a20;
    int f24;
    RefObj* owner;
};

class BlendFrameController {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void vfunc_14(int a, float b);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void vfunc_24(RefObj* obj, float start, float blend);
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void vfunc_29();
    char pad04[0x1c - 4];
    int pad1c;
    int f20;
    int f24;
    unsigned int count;
    Track tracks[4];
};

void BlendFrameController::vfunc_24(RefObj* obj, float start, float blend)
{
    float len = obj->length - 1.0f;
    if (len < 0.0f)
        len = 0.0f;
    if (blend > 0.0f) {
        if (count == 5)
            vfunc_29();
        Track* t = &tracks[count];
        obj->AddRef();
        if (t->owner != 0)
            t->owner->Release();
        t->owner = obj;
        float r;
        if (start >= 0.0f && start <= len)
            r = start;
        else if (start > len)
            r = len;
        else
            r = 0.0f;
        tracks[count].cur = r;
        tracks[count].remain = blend;
        tracks[count].fadeRate = 1.0f / blend;
        tracks[count].weight = 0.0f;
        tracks[count].f1c = f24;
        tracks[count].a20 = f20;
        if (count == 0)
            tracks[0].weight = 1.0f;
        count = count + 1;
        vfunc_14(0, len);
        return;
    }
    obj->AddRef();
    if (tracks[0].owner != 0)
        tracks[0].owner->Release();
    tracks[0].owner = obj;
    float r;
    if (start >= 0.0f && start <= len)
        r = start;
    else if (start > len)
        r = len;
    else
        r = 0.0f;
    tracks[0].cur = r;
    tracks[0].f1c = f24;
    tracks[0].remain = 0.0f;
    tracks[0].fadeRate = 0.0f;
    tracks[0].weight = 1.0f;
    tracks[0].a20 = f20;
    for (unsigned int i = 1; i < count; i++) {
        if (tracks[i].owner != 0)
            tracks[i].owner->Release();
        tracks[i].owner = 0;
    }
    count = 1;
    vfunc_14(0, len);
}
