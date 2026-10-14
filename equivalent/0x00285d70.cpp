// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00285d70 @ 0x00285d70
namespace pure3d {

class __declspec(novtable) Entity {
public:
    virtual void e0();
    char pad4[4];
    int name0;
    int name1;
    void FUN_0027b0b0(const Entity* src);
    Entity(const Entity& src) throw() { FUN_0027b0b0(&src); }
};

class FrameController : public Entity {
public:
    char flag10;
    char pad11[7];
    FrameController(const FrameController& src) throw() : Entity(src) { flag10 = src.flag10; }
};

class AnimationFrameController : public FrameController {
public:
    int f18;
    AnimationFrameController(const AnimationFrameController& src) throw() : FrameController(src) { f18 = src.f18; }
};

class RefObj_285d70 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct Track {
    float cur;
    int a4;
    int a8;
    float remain;
    float fadeRate;
    float weight;
    float f18;
    int f1c;
    int a20;
    char f24;
    char pad25[3];
    RefObj_285d70* owner;
};

class BlendFrameController : public AnimationFrameController {
public:
    int f1c;
    int f20;
    int f24;
    unsigned int count;
    Track tracks[5];
    char dirty;
    BlendFrameController(const BlendFrameController& src) throw();
};

BlendFrameController::BlendFrameController(const BlendFrameController& src) throw()
    : AnimationFrameController(src)
{
    f20 = src.f20;
    f24 = src.f24;
    for (int i = 0; i < 5; i++) {
        Track& t = tracks[i];
        t.cur = 0.0f;
        t.a4 = 0;
        t.a8 = 0;
        t.remain = 0.0f;
        t.fadeRate = 0.0f;
        t.weight = 0.0f;
        t.f18 = 3.4028235e+38f;
        t.f1c = 0;
        t.a20 = 0;
        t.f24 = 1;
        t.owner = 0;
    }
    dirty = 0;
    count = 0;
    while (count < src.count) {
        unsigned int idx = count;
        RefObj_285d70* o = src.tracks[idx].owner;
        if (o != 0)
            o->AddRef();
        if (tracks[idx].owner != 0)
            tracks[idx].owner->Release();
        tracks[idx].owner = o;
        tracks[count].cur = src.tracks[count].cur;
        tracks[count].a4 = src.tracks[count].a4;
        tracks[count].a8 = src.tracks[count].a8;
        tracks[count].remain = src.tracks[count].remain;
        tracks[count].fadeRate = src.tracks[count].fadeRate;
        tracks[count].weight = src.tracks[count].weight;
        tracks[count].f18 = src.tracks[count].f18;
        tracks[count].f1c = src.tracks[count].f1c;
        tracks[count].a20 = src.tracks[count].a20;
        count = count + 1;
    }
}

}
