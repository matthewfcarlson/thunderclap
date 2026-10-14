// STATUS: equivalent (tools/equiv.py level 3: 671 inputs, branch coverage 6/6)
// pure3d::prop::StateProp::vfunc_8 @ 0x0027caa0
class Child_27caa0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(int a, int b);
};

struct Entry_27caa0 {
    Child_27caa0* child;       // 0x0
    int pad4;
    unsigned int flags; // 0x8
};

class Device_27caa0 {
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16(int a);
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23(int a, int b);
};

struct Context {
    Device_27caa0* device;
};
extern Context* DAT_0052c2ac;

class StateProp {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(int a, int b);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual int vfunc_15();
    virtual void vfunc_16();
    char pad04[0x9c - 4];
    Child_27caa0* drawable;        // 0x9c
    char padA0[0xb4 - 0xa0];
    int entryCount;         // 0xb4
    Entry_27caa0 entries[1];       // 0xb8
};

void StateProp::vfunc_8(int a, int b)
{
    for (int i = 0; i < entryCount; i++) {
        if (entries[i].flags & 2)
            entries[i].child->vfunc_8(a, b);
    }
    int v = vfunc_15();
    DAT_0052c2ac->device->vfunc_23(0, v);
    drawable->vfunc_8(a, b);
    DAT_0052c2ac->device->vfunc_16(0);
}
