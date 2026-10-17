// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000a9170 @ 0x000a9170
struct Object { char padding[0xd0]; int flag; char rest[0x80]; int selected; char gap[8]; int alternate; };
Object* __stdcall FUN_000a9170(Object* first, Object* second) {
    if (first->flag && !second->flag)
        return (Object*)&first->alternate;
    return (Object*)&second->selected;
}