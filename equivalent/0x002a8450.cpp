// STATUS: equivalent (tools/equiv.py level 3: 141 inputs, branch coverage 18/22, incomplete)
// pure3d::ShaderAnimationController::vfunc_7 @ 0x002a8450
namespace pure3d {

struct Vec3_2a8450 {
    float x, y, z;
};

struct Quat_2a8450 {
    float x, y, z, w;
};

class Entity {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
};

class Texture : public Entity {
public:
    char pad04[0x10 - 4];
    int handle;               // 0x10
};

// Target of the animated shader parameters (slots 5..10 set one parameter each).
class ParamSink {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(int id, int tex);
    virtual void s6(int id, int value);
    virtual void s7(int id, float value);
    virtual void s8(int id, int color);
    virtual void s9(int id, const Vec3_2a8450 *v);
    virtual void s10(int id, const Quat_2a8450 *q);
};

struct SinkHolder_2a8450 {
    char pad00[0x10];
    ParamSink *sink;          // 0x10
};

// One animated channel of the shader animation; the vtable slot 2 returns a fourcc type tag.
class Channel {
public:
    virtual void c0();
    virtual void c1();
    virtual unsigned int type();
    virtual void c3();
    virtual void sampleVec3(float frame, Vec3_2a8450 *out);
    virtual void c5();
    virtual void sampleQuat(float frame, Quat_2a8450 *out);
    char pad04[4];
    int paramId;              // 0x08
    void FUN_0028a0b0(float frame, int *out);
    void FUN_0028ac00(float frame, Entity **out);
    void FUN_0028ad20(float frame, int *out);
    void FUN_0028ac90(float frame, unsigned char *out);
    void FUN_0028a1c0(float frame, float *out);
};

struct ChannelList_2a8450 {
    char pad00[0x14];
    int count;                // 0x14
    Channel *FUN_00288950(int index);
};

struct Animation {
    ChannelList_2a8450 *FUN_00288a10(int index);
};

class ShaderAnimationController {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    char pad04[0x34 - 4];
    float frame;              // 0x34
    char pad38[4];
    Animation *anim;          // 0x3c
    SinkHolder_2a8450 *target;       // 0x40

};

void ShaderAnimationController::vfunc_7()
{
    ChannelList_2a8450 *list = anim->FUN_00288a10(0);
    for (int i = 0; i < list->count; i++) {
        Channel *ch = list->FUN_00288950(i);
        switch (ch->type()) {
        case 0x544f52: {
            Quat_2a8450 q;
            ch->sampleQuat(frame, &q);
            target->sink->s10(ch->paramId, &q);
            break;
        }
        case 0x524c43: {
            int color;
            ch->FUN_0028ad20(frame, &color);
            target->sink->s8(ch->paramId, color);
            break;
        }
        case 0x544e45: {
            Entity *e;
            ch->FUN_0028ac00(frame, &e);
            int id = ch->paramId;
            Texture *t = dynamic_cast<Texture *>(e);
            if (t)
                target->sink->s5(id, t->handle);
            else
                target->sink->s5(id, 0);
            break;
        }
        case 0x544e49: {
            int value;
            ch->FUN_0028a0b0(frame, &value);
            target->sink->s6(ch->paramId, value);
            break;
        }
        case 0x31544c46: {
            float f;
            ch->FUN_0028a1c0(frame, &f);
            target->sink->s7(ch->paramId, f);
            break;
        }
        case 0x4c4f4f42: {
            unsigned char b;
            ch->FUN_0028ac90(frame, &b);
            target->sink->s6(ch->paramId, b);
            break;
        }
        case 0x54434556: {
            Vec3_2a8450 v;
            ch->sampleVec3(frame, &v);
            target->sink->s9(ch->paramId, &v);
            break;
        }
        default:
            break;
        }
    }
}

}
