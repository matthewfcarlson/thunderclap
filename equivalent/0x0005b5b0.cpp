// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// CGrappleSoundTrack::vfunc_12 @ 0x0005b5b0
struct Settings;
struct Slot_5b5b0 {
    char pad00[0x104];
    Settings* settings;
};
struct Fighter_5b5b0 {
    char pad00[0x330];
    Slot_5b5b0* primary;
    Slot_5b5b0* secondary;
};
struct Context {
    Fighter_5b5b0* FUN_00059a30();
};
struct Owner_5b5b0 {
    Context* FUN_000592a0();
};
class CGrappleSoundTrack;
struct Created_5b5b0 {
    void* FUN_0001d190(CGrappleSoundTrack* track, Settings* settings);
};
void* __cdecl FUN_0008d690(unsigned int size);

class CGrappleSoundTrack {
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
    void* v12(Owner_5b5b0* owner);
};

void* CGrappleSoundTrack::v12(Owner_5b5b0* owner)
{
    if (owner == 0)
        return 0;
    Context* ctx = owner->FUN_000592a0();
    if (ctx == 0)
        return 0;
    Fighter_5b5b0* fighter = ctx->FUN_00059a30();
    if (fighter == 0)
        return 0;
    Slot_5b5b0* slot = fighter->secondary;
    if (slot == 0)
        slot = fighter->primary;
    if (slot == 0)
        return 0;
    Settings* settings = slot->settings;
    if (settings == 0)
        return 0;
    Created_5b5b0* c = static_cast<Created_5b5b0*>(FUN_0008d690(0x24));
    if (c == 0)
        return 0;
    return c->FUN_0001d190(this, settings);
}
