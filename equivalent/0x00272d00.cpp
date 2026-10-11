// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00272d00 @ 0x00272d00
namespace core {
struct IRefCount { static unsigned int vftable[]; };
struct Object { static unsigned int vftable[]; };
struct SafeRefCount { static unsigned int vftable[]; };
struct Drive { static unsigned int vftable[]; static unsigned int vftable_4[]; static unsigned int vftable_c[]; };
}
extern int DAT_004cdbb0;
void __cdecl FUN_002705f0();
struct DrivePart { void FUN_00277a40(); };
struct DriveObject {
    unsigned int *primaryVtable;
    unsigned int *objectVtable;
    int identifier;
    unsigned int *refVtable;
    int count;
    DrivePart part;
    char pad[0x38-0x15];
    int values[7];
    unsigned char flag54;
    char pad55[3];
    int value58;
    unsigned char flag5c;
    unsigned char flag5d;
    char pad5e[0xb4-0x5e];
    int state;
    int valueb8;
    DriveObject *FUN_00272d00();
};
DriveObject *DriveObject::FUN_00272d00() {
    primaryVtable = core::IRefCount::vftable;
    objectVtable = core::Object::vftable;
    identifier = DAT_004cdbb0;
    FUN_002705f0();
    refVtable = core::SafeRefCount::vftable;
    count = 1;
    primaryVtable = core::Drive::vftable;
    objectVtable = core::Drive::vftable_4;
    refVtable = core::Drive::vftable_c;
    part.FUN_00277a40();
    for (int i = 0; i < 7; ++i) values[i] = 0;
    flag54 = 0;
    value58 = 0;
    flag5c = 1;
    flag5d = 0;
    state = 3;
    valueb8 = 0;
    FUN_002705f0();
    return this;
}