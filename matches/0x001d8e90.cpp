#include "decls/address.h"
struct Resource_1d8e90 {
    virtual void slot0();
    virtual void release();
};
struct Controller_1d8e90 {
    char pad0[8];
    unsigned int field8, fieldC;
    char pad10[0x74];
    unsigned char active;
    void FUN_002fd8a0(int);
};
struct Link_1d8e90 {
    char pad[0x10];
    Controller_1d8e90* controller;
};
struct Manager_1d8e90 {
    void FUN_00067c80(void*);
};
struct Subsystem_1d8e90 {
    char pad[8];
    Manager_1d8e90* manager;
};
struct World {
    char pad[0x20];
    Subsystem_1d8e90* subsystem;
};
struct Handle_1d8e90 {
    void FUN_0027af50();
    char bytes[12];
};
struct A_1d8e90 {
    void FUN_001b4540();
};
struct B_1d8e90 {
    void FUN_001c3b80(void*);
};
struct CSPHulkPropInstance;
A_1d8e90* __stdcall FUN_001b6580(CSPHulkPropInstance*);
B_1d8e90* FUN_001c3d90();  // 0-argument singleton getter
struct CSPHulkPropInstance {
    virtual void slot0();
    virtual void slot1();
    char pad4[0x9c];
    Link_1d8e90* link;
    char padA4[0x70];
    Resource_1d8e90* r114;
    Resource_1d8e90* r118;
    Resource_1d8e90* r11c;
    Resource_1d8e90* r120;
    char pad124[0x10];
    Resource_1d8e90* r134;
    char pad138[0x94];
    void* r1cc;
    char pad1d0[12];
    Resource_1d8e90* r1dc;
    char pad1e0[0x60];
    Handle_1d8e90 handle;
    Resource_1d8e90* r24c;
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
        Controller_1d8e90* c = link->controller;
        bool active = c->active != 0;
        c->fieldC = 0;
        c->field8 = 0;
        if (active)
            c->FUN_002fd8a0(0);
    }
    FUN_001b6580(this)->FUN_001b4540();
    FUN_001c3d90()->FUN_001c3b80((char*)this + 8);
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
