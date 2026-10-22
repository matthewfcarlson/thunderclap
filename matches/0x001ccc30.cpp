struct Check {
    int FUN_00086280();
};
struct Object {
    void FUN_000d4820(int zero, void* arg);
};
struct Entry {
    char pad0[4];
    Object* value;
};
struct Owner {
    char pad0[0x3c];
    Entry* entry;
    char pad1[0x14];
    Check* check;
};
struct CScenarioManager_1ccc30 {
    char pad0[4];
    Owner* owner;
    char pad1[0x11a0];
    void* stored;
    void FUN_001ccc30(void* volatile arg);
};
void CScenarioManager_1ccc30::FUN_001ccc30(void* volatile arg) {
    stored = arg;
    Object* object;
    if (owner && owner->check && owner->check->FUN_00086280() && owner->entry && owner->entry->value)
        object = owner->entry->value;
    else
        object = 0;
    object->FUN_000d4820(0, arg);
}