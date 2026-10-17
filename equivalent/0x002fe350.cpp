// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// physics::SimStateHairclub::vfunc_5 @ 0x002fe350
struct HairEntry { char header[0x30]; char data[0x10]; };
struct HairStorage { char pad[0x1c]; HairEntry* entries; };
struct HairLookup { char pad[0x20]; void* value; int FUN_00304cb0(void*, int); };
namespace physics {
struct SimStateHairclub {
    char pad[0x40];
    char fallback[0x34];
    HairLookup* lookup;
    char pad2[0x10];
    HairStorage* storage;
    void* vfunc_5(int index);
};
void* SimStateHairclub::vfunc_5(int index) {
    if (index >= 0) {
        int found = lookup->FUN_00304cb0(lookup->value, index);
        if (found >= 0)
            return storage->entries[found].data;
    }
    return fallback;
}
}