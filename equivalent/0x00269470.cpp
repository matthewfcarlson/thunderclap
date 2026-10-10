// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 13/14, incomplete)
// core::ControllerSystemXBox::vfunc_5 @ 0x00269470
namespace core {
struct ControllerDevice {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual const char* vfunc_6();
    char padding[0x4a0 - 4];
};
struct ControllerSystemXBox {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual ControllerDevice* vfunc_5(const char* name);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    char padding[0x20 - 4];
    ControllerDevice devices[4];
};
ControllerDevice* ControllerSystemXBox::vfunc_5(const char* name) {
    for (unsigned i = 0; i < 4; ++i) {
        ControllerDevice* device = &devices[i];
        if (!device->vfunc_3()) continue;
        const char* candidate = device->vfunc_6();
        const char* requested = name;
        while (*candidate && *candidate == *requested) {
            ++candidate;
            ++requested;
        }
        if (*candidate == *requested) return device;
    }
    return 0;
}
}