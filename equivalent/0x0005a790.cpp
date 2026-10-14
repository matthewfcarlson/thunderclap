// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleAutoTargetTrack::vfunc_12 @ 0x0005a790
struct Settings;
struct Slot_5a790 {
    char pad00[0x104];
    Settings* settings;
};
struct Fighter_5a790 {
    char pad00[0x330];
    Slot_5a790* primary;
    Slot_5a790* secondary;
};
struct Context {
    Fighter_5a790* FUN_00059a30();
};
struct Owner_5a790 {
    Context* FUN_000592a0();
};
class CGrappleAutoTargetTrack;
struct Created_5a790 {
    void* FUN_0001d4c0(CGrappleAutoTargetTrack* track, Settings* settings);
};
void* __cdecl FUN_0008d690(unsigned int size);

class CGrappleAutoTargetTrack {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    void* v12(Owner_5a790* owner);
};

void* CGrappleAutoTargetTrack::v12(Owner_5a790* owner)
{
    if (owner == 0)
        return 0;
    Context* ctx = owner->FUN_000592a0();
    if (ctx == 0)
        return 0;
    Fighter_5a790* fighter = ctx->FUN_00059a30();
    if (fighter == 0)
        return 0;
    Slot_5a790* slot = fighter->secondary;
    if (slot == 0)
        slot = fighter->primary;
    if (slot == 0)
        return 0;
    Settings* settings = slot->settings;
    if (settings == 0)
        return 0;
    Created_5a790* c = static_cast<Created_5a790*>(FUN_0008d690(0x30));
    if (c == 0)
        return 0;
    return c->FUN_0001d4c0(this, settings);
}
