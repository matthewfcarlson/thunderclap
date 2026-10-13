struct Resource {
    virtual void slot0();
    virtual void release();
};
struct Controller {
    char pad0[8];
    unsigned int field8, fieldC;
    char pad10[0x74];
    unsigned char active;
    void FUN_002fd8a0(int);
};
struct Link {
    char pad[0x10];
    Controller* controller;
};
struct Manager {
    void FUN_00067c80(void*);
};
struct Subsystem {
    char pad[8];
    Manager* manager;
};
struct Global {
    char pad[0x20];
    Subsystem* subsystem;
};
extern Global* DAT_004dd700;
struct Handle {
    void FUN_0027af50();
    char bytes[12];
};
struct A {
    void FUN_001b4540();
};
struct B {
    void FUN_001c3b80();
};
struct CSPHulkPropInstance;
A* __stdcall FUN_001b6580(CSPHulkPropInstance*);
B* __stdcall FUN_001c3d90(void*);
struct CSPHulkPropInstance {
    virtual void slot0();
    virtual void slot1();
    char pad4[0x9c];
    Link* link;
    char padA4[0x70];
    Resource* r114;
    Resource* r118;
    Resource* r11c;
    Resource* r120;
    char pad124[0x10];
    Resource* r134;
    char pad138[0x94];
    void* r1cc;
    char pad1d0[12];
    Resource* r1dc;
    char pad1e0[0x60];
    Handle handle;
    Resource* r24c;
    void FUN_001d8cd0();
    void FUN_001d8100();
    void FUN_0027e2d0();
    ~CSPHulkPropInstance();
};
CSPHulkPropInstance::~CSPHulkPropInstance() {
    FUN_001d8cd0();
    if (r24c) {
        r24c->release();
        r24c = 0;
    }
    if (r1cc) {
        DAT_004dd700->subsystem->manager->FUN_00067c80(r1cc);
        r1cc = 0;
    }
    FUN_001d8100();
    if (r120) {
        r120->release();
        r120 = 0;
    }
    if (r134) {
        r134->release();
        r134 = 0;
    }
    if (link && link->controller) {
        Controller* c = link->controller;
        bool active = c->active != 0;
        c->fieldC = 0;
        c->field8 = 0;
        if (active)
            c->FUN_002fd8a0(0);
    }
    FUN_001b6580(this)->FUN_001b4540();
    FUN_001c3d90((char*)this + 8)->FUN_001c3b80();
    if (r11c) {
        r11c->release();
        r11c = 0;
    }
    if (r118) {
        r118->release();
        r118 = 0;
    }
    if (r114) {
        r114->release();
        r114 = 0;
    }
    if (r1dc)
        r1dc->release();
    r1dc = 0;
    handle.FUN_0027af50();
    FUN_0027e2d0();
}
