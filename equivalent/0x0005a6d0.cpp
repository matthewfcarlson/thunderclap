// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleKeyPoseTrack::vfunc_12 @ 0x0005a6d0
struct Settings;
struct Slot {
    char pad00[0x104];
    Settings* settings;
};
struct Fighter {
    char pad00[0x330];
    Slot* primary;
    Slot* secondary;
};
struct Context {
    Fighter* FUN_00059a30();
};
struct Owner {
    Context* FUN_000592a0();
};
class CGrappleKeyPoseTrack;
struct Created {
    void* FUN_0001d100(CGrappleKeyPoseTrack* track, Settings* settings);
};
void* __cdecl FUN_0008d690(unsigned int size);

class CGrappleKeyPoseTrack {
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
    void* v12(Owner* owner);
};

void* CGrappleKeyPoseTrack::v12(Owner* owner)
{
    if (owner == 0)
        return 0;
    Context* ctx = owner->FUN_000592a0();
    if (ctx == 0)
        return 0;
    Fighter* fighter = ctx->FUN_00059a30();
    if (fighter == 0)
        return 0;
    Slot* slot = fighter->secondary;
    if (slot == 0)
        slot = fighter->primary;
    if (slot == 0)
        return 0;
    Settings* settings = slot->settings;
    if (settings == 0)
        return 0;
    Created* c = static_cast<Created*>(FUN_0008d690(0x30));
    if (c == 0)
        return 0;
    return c->FUN_0001d100(this, settings);
}
