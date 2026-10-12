// STATUS: equivalent (tools/equiv.py level 3: 1194 inputs, branch coverage 16/16)
// FUN_002a6610 @ 0x002a6610
class Overlay;
struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Vec2 {
    float x, y;
    float FUN_002a54e0();
};

class Node {
public:
    virtual void s0();
    virtual void s1();
    virtual int type();
    virtual void s3();
    virtual void direction(float v, Vec3 *out);
    char pad4[8 - 4];
    int subtype;
    void FUN_0028a1c0(float v, float *target);
};

class List {
public:
    char pad0[0x14];
    int count;
    Node *FUN_00288950(int index);
};

class Overlay {
public:
    List *FUN_00288a10(int flag);
};

class Controller {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual float f10();
    virtual void s11();
    virtual void s12();
    virtual float f13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual Overlay *f25();
};

struct Settings {
    float sp;
    float su;
    Vec3 dir;
    Vec2 d;
};

void FUN_002a5290(float v, unsigned int a, unsigned int b, unsigned int c, Settings *s);

void FUN_002a6610(Controller *c, unsigned int a2, unsigned int a3, unsigned int a4)
{
    struct Frame {
        float timeA;
        float timeB;
        Settings s;
    } fr;

    float t = c->f13();
    fr.timeB = t;
    fr.timeA = t;
    List *list = c->f25()->FUN_00288a10(0);
    fr.s.sp = 0.1f;
    fr.s.su = 0.1f;
    fr.s.dir.x = 1.0f;
    fr.s.dir.y = 0.0f;
    fr.s.dir.z = 0.0f;
    fr.s.d.x = 1.0f;
    fr.s.d.y = 0.0f;

    for (int i = 0; i < list->count; i++) {
        float v = fr.timeB;
        Node *n = list->FUN_00288950(i);
        int ty = n->type();
        if (ty == 0x31544c46) {
            float *target;
            if (n->subtype == 0x50535053)
                target = &fr.s.sp;
            else if (n->subtype == 0x50535553)
                target = &fr.s.su;
            else if (n->subtype == 0x454d4954)
                target = &fr.timeA;
            else
                continue;
            n->FUN_0028a1c0(v, target);
        } else if (ty == 0x54434556) {
            if (n->subtype == 0x52494453) {
                n->direction(v, &fr.s.dir);
                float x = fr.s.dir.x;
                float y = fr.s.dir.y;
                fr.s.d.x = x;
                fr.s.d.y = y;
                fr.s.dir.FUN_0022d110();
                fr.s.d.FUN_002a54e0();
            }
        }
    }
    FUN_002a5290(fr.timeA / c->f10(), a2, a3, a4, &fr.s);
}
