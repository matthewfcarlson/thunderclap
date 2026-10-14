// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 31/34, incomplete)
// FUN_000e8cf0 @ 0x000e8cf0
class FEObject {
public:
    virtual void o0();
};

class Widget_e8cf0 {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual bool w4(int a, int b, int c, int d);
};

class FEControl : public FEObject {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void vfn13(int mode);
    virtual void vfn14(int mode);
    char pad0[0xa8 - 4];
    int value;
    char pad1[0x118 - 0xac];
    Widget_e8cf0 *widgets[10];
};

class Engine_e8cf0 {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual void e17();
    virtual void e18();
    virtual void e19();
    virtual void e20();
    virtual void e21();
    virtual void e22();
    virtual void e23();
    virtual void e24();
    virtual void e25();
    virtual void e26();
    virtual void e27();
    virtual void e28();
    virtual void e29();
    virtual void e30();
    virtual void e31();
    virtual void e32();
    virtual void e33();
    virtual void e34();
    virtual void e35();
    virtual void e36();
    virtual void e37();
    virtual void e38();
    virtual void e39();
    virtual void e40();
    virtual void e41();
    virtual void e42();
    virtual void e43();
    virtual void e44();
    virtual void e45();
    virtual void e46();
    virtual void e47();
    virtual void vfn48(int mode);
};

class Manager_e8cf0 {
public:
    virtual void m0();
    Engine_e8cf0 *engine;
};

struct Item_e8cf0 {
    FEObject *obj;
    int pad[2];
    char flag;
    char pad2[3];
};

class VScroll {
public:
    virtual void v0();
    char pad04[4];
    Manager_e8cf0 *manager;
    char padC[0x40 - 0xc];
    Item_e8cf0 items[32];
    char pad240[4];
    FEControl *selected;    // 0x244
    int index;
    int cursor;
    char pad250[0x268 - 0x250];
    int cursorMax;
    void FUN_000e23f0();
    void FUN_000e8cf0(int index, int mode);
};

void VScroll::FUN_000e8cf0(int idx, int mode)
{
    bool forward = (mode == 2);
    int i;
    FEControl *cur = selected;
    if (cur != 0) {
        for (i = 0; i < 10; i++) {
            Widget_e8cf0 *w = cur->widgets[i];
            if (w == 0) break;
            if (w->w4(3, cur->value, -1, -1))
                cur->widgets[i]->w1();
        }
        selected->vfn14(forward ? 2 : 1);
    }
    index = idx;
    FEControl *cast = dynamic_cast<FEControl *>(items[idx].obj);
    Manager_e8cf0 *mgr = manager;
    selected = cast;
    mgr->engine->vfn48(2);
    if (items[index].flag == 0) {
        for (int n = 1000000; n > 0; n--) {
            if (forward)
                cursor++;
            else
                cursor--;
            if (cursor < 0) {
                cursor += 2;
                forward = true;
            }
            if (cursor > cursorMax)
                cursor = 0;
            FUN_000e23f0();
            if (items[index].flag != 0)
                break;
        }
    }
    if (selected != 0) {
        selected->vfn13(forward ? 2 : 1);
        FEControl *s = selected;
        for (i = 0; i < 10; i++) {
            Widget_e8cf0 *w = s->widgets[i];
            if (w == 0) break;
            if (w->w4(2, s->value, -1, -1))
                s->widgets[i]->w1();
        }
    }
}
