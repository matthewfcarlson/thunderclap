#include "decls/address.h"
struct Bounds_1d8d90 {
    unsigned int values[4];
};
struct Descriptor_1d8d90 {
    unsigned int kind;
    Bounds_1d8d90 bounds;
    char rest[12];
    void FUN_00067e20();
    void FUN_000679c0();
};
struct Manager_1d8d90 {
    unsigned int FUN_00067ba0();
    void FUN_00067c80(unsigned int);
    void FUN_00067c30(unsigned int, Descriptor_1d8d90*);
};
struct Subsystem_1d8d90 {
    char pad[8];
    Manager_1d8d90* manager;
};
struct World {
    char pad[32];
    Subsystem_1d8d90* subsystem;
};
struct Inner_1d8d90 {
    char pad[16];
    unsigned int* value;
};
struct Link_1d8d90 {
    char pad[8];
    Inner_1d8d90* inner;
    unsigned int type;
};
struct Component_1d8d90 {
    void FUN_0027b040(int);
};
struct Object {
    char pad0[0x118];
    Link_1d8d90* link;
    char pad1[0xad];
    unsigned char active;
    char pad2[2];
    unsigned int handle;
    char pad3[0x70];
    Component_1d8d90 component;
    void FUN_001d8cd0();
    void FUN_001d71e0(int);
    unsigned char FUN_001d7360(Bounds_1d8d90*);
    void FUN_001d8d90(unsigned char enabled);
};
void Object::FUN_001d8d90(unsigned char enabled) {
    if (enabled == active)
        return;
    active = enabled;
    if (!enabled) {
        if (handle) {
            DAT_004dd700->subsystem->manager->FUN_00067c80(handle);
            handle = 0;
        }
        FUN_001d8cd0();
        component.FUN_0027b040(0);
        FUN_001d71e0(0);
        return;
    }
    Bounds_1d8d90 bounds;
    if (FUN_001d7360(&bounds)) {
        Manager_1d8d90* manager = DAT_004dd700->subsystem->manager;
        handle = manager->FUN_00067ba0();
        Descriptor_1d8d90 descriptor;
        descriptor.FUN_00067e20();
        descriptor.bounds = bounds;
        if (link && link->type == 1 && link->inner)
            descriptor.kind = *link->inner->value;
        manager->FUN_00067c30(handle, &descriptor);
        descriptor.FUN_000679c0();
    }
}
