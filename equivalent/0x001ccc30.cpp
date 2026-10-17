// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001ccc30 @ 0x001ccc30
struct Check { int FUN_00086280(); };
struct Object { void FUN_000d4820(int zero, void *arg); };
struct Entry { char pad0[4]; Object *value; };
struct Owner { char pad0[0x3c]; Entry *entry; char pad1[0x14]; Check *check; };
struct Target { char pad0[4]; Owner *owner; char pad1[0x11a0]; void *stored; void FUN_001ccc30(void *arg); };
void Target::FUN_001ccc30(void *arg) {
    stored = arg;
    Object *object = 0;
    if (owner && owner->check && owner->check->FUN_00086280() && owner->entry)
        object = owner->entry->value;
    object->FUN_000d4820(0, arg);
}