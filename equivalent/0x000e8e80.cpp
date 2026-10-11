// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 29/34, incomplete)
// VScroll::vfunc_7 @ 0x000e8e80
class FEObject {
public:
    virtual void o0();
};

class FEControl : public FEObject {
public:
    virtual void c0();
};

class Child {
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
    virtual char vfunc_12(int a, int b);
};

class Manager {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual int vfunc_17();
};

struct Item {
    FEObject *obj;
    int pad[3];
};

class FELayout {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
};

class VScroll : public FELayout {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v5();
    virtual void v6();
    virtual char vfunc_7(int event, int arg);
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
    virtual void v21();
    char pad04[4];
    Manager *manager;
    char padC[0x40 - 0xc];
    Item items[32];
    char pad240[4];
    Child *child;
    int index;
    char pad24c[0x268 - 0x24c];
    int fallbackIndex;
    void FUN_000e8cf0(int index, int mode);
};

char VScroll::vfunc_7(int event, int arg)
{
    if (child != 0) {
        if (child->vfunc_12(event, arg))
            return 1;
    }

    if (event == 0) {
        int i = index - 1;
        while (i >= 0) {
            FEObject *obj = items[i].obj;
            if (obj != 0 && dynamic_cast<FEControl *>(obj) != 0) {
                FUN_000e8cf0(i, 1);
                break;
            }
            i--;
        }
        if (i != -1)
            return 1;
        if (manager->vfunc_17() == 1)
            FUN_000e8cf0(0, 1);
        return 0;
    }

    if (event == 4) {
        int i = index + 1;
        while (i < 32) {
            FEObject *obj = items[i].obj;
            if (obj == 0)
                break;
            if (dynamic_cast<FEControl *>(obj) != 0) {
                FUN_000e8cf0(i, 2);
                break;
            }
            i++;
        }
        if (i != 32) {
            if (items[i].obj != 0)
                return 1;
        }
        if (manager->vfunc_17() == 1) {
            FUN_000e8cf0(fallbackIndex, 2);
            return 0;
        }
    }
    return 0;
}
