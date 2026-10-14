struct Text_1ec980 {
    char storage[0x48];
    void FUN_001ef320();
    void FUN_001ef370(const char*);
    void FUN_001ef350();
};
struct Object {
    const char* FUN_000443b0();
};
struct Actor_1ec980 {
    char pad[8];
    char location[0x114];
    Object* object;
    char gap[8];
    void* alternate;
};
struct Service_1ec980 {
    void FUN_00086310();
};
struct Output_1ec980 {
    void FUN_001efe20(Text_1ec980*, void*, int, float);
};
struct Global_1ec980 {
    Output_1ec980* output;
    char pad[4];
    unsigned char enabled;
};
extern Global_1ec980* DAT_004e36d8;
struct Target_1ec980 {
    char pad[4];
    Service_1ec980* service;
    void FUN_001ebd80(void*, int, float, int);
    void FUN_001ec980(Actor_1ec980*, int);
};
void Target_1ec980::FUN_001ec980(Actor_1ec980* actor, int value) {
    if (!actor || !actor->object)
        return;
    if (actor->alternate) {
        FUN_001ebd80(actor->alternate, value, 100.0f, 0);
        return;
    }
    Text_1ec980 text;
    text.FUN_001ef320();
    text.FUN_001ef370("Objects");
    text.FUN_001ef370("Actors");
    text.FUN_001ef370(actor->object->FUN_000443b0());
    service->FUN_00086310();
    if (DAT_004e36d8->enabled)
        DAT_004e36d8->output->FUN_001efe20(&text, actor->location, value, 100.0f);
    text.FUN_001ef350();
}
