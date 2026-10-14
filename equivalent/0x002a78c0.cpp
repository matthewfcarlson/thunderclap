// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 12/12)
// pure3d::SceneGraphTransformAnimationController::vfunc_28 @ 0x002a78c0
struct V3_2a78c0 { float x, y, z; };

struct Matrix {
    float r[12];
    V3_2a78c0 pos;
    float w;
};

struct Quat_2a78c0 {
    float x, y, z, w;
    void FUN_0022b750(const Quat_2a78c0* a, const Quat_2a78c0* b, float t);
    void FUN_0022b650(Matrix* m);
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float t, V3_2a78c0* out);
    virtual void vf5(float t, Quat_2a78c0* out);
};

class ChannelSet_2a78c0 {
public:
    Channel* FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

class Source_2a78c0 {
public:
    ChannelSet_2a78c0* FUN_00288a10(int index);
};

class Node {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(int a, int b, int c, int d);
    char pad04[0x14 - 4];
    Node* child;
    char pad18[0x28 - 0x18];
    Matrix xform;
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
    Source_2a78c0* owner;
    Source_2a78c0* FUN_00284f50();
    float FUN_00284f70();
    float FUN_00284f60();
};

class SceneGraphTransformAnimationController {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void vfunc_28();
    virtual void v29();
    char pad04[0x28 - 4];
    unsigned int count;
    Track tracks[5];
    char pad108[0x110 - 0x108];
    Node* target;
};

void SceneGraphTransformAnimationController::vfunc_28()
{
    struct Frame {
        float w;
        float inv;
        unsigned int i;
        float cur;
        V3_2a78c0 acc;
        V3_2a78c0 t;
        Quat_2a78c0 q;
        Quat_2a78c0 r;
    } fr;
    fr.acc.x = 0.0f;
    fr.acc.y = 0.0f;
    fr.acc.z = 0.0f;
    fr.q.x = 0.0f;
    fr.q.y = 0.0f;
    fr.q.z = 0.0f;
    fr.q.w = 1.0f;
    fr.i = 0;
    if (count != 0) {
        Track* trk = &tracks[0];
        do {
            Source_2a78c0* src = trk->FUN_00284f50();
            ChannelSet_2a78c0* cs = src->FUN_00288a10(0);
            fr.cur = trk->FUN_00284f70();
            fr.w = trk->FUN_00284f60();
            fr.inv = 1.0f - fr.w;
            Channel* rot = cs->FUN_00288960(0x544f52, 0x544f52);
            if (rot != 0) {
                rot->vf5(fr.cur, &fr.r);
                fr.q.FUN_0022b750(&fr.q, &fr.r, fr.w);
            }
            Channel* pos = cs->FUN_00288960(0x4e415254, 0x54434556);
            if (pos != 0) {
                fr.acc.x = fr.acc.x * fr.inv;
                fr.acc.y = fr.acc.y * fr.inv;
                fr.acc.z = fr.acc.z * fr.inv;
                pos->vf4(fr.cur, &fr.t);
                fr.acc.x = fr.t.x * fr.w + fr.acc.x;
                fr.acc.y = fr.t.y * fr.w + fr.acc.y;
                fr.acc.z = fr.t.z * fr.w + fr.acc.z;
            }
            fr.i++;
            trk++;
        } while (fr.i < count);
    }
    Node* n = target;
    n->vf10(1, 6, 2, 1);
    if (n->child != 0)
        n->child->vf10(1, 2, 1, 1);
    fr.q.FUN_0022b650(&n->xform);
    n = target;
    n->vf10(1, 6, 2, 1);
    if (n->child != 0)
        n->child->vf10(1, 2, 1, 1);
    n->xform.pos.x = fr.acc.x;
    n->xform.pos.y = fr.acc.y;
    n->xform.pos.z = fr.acc.z;
}
