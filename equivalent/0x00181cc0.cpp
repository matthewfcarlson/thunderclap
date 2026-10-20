// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 8/8)
// hulkfight::motion::PropGrabbableIsThrownCondition::vfunc_6 @ 0x00181cc0
extern char DAT_00494b44;
extern char DAT_00494b60;
void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Actor;
struct Owner { Actor* FUN_00059a30(); };
struct Input { Owner* FUN_000592a0(); };
struct Object { char pad[0x1c9]; unsigned char state; };
struct Entry { char pad[8]; Object* object; int kind; };
struct Actor { char pad[0x3a4]; Entry* entry; };
struct PropGrabbableIsThrownCondition_181cc0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual int vfunc_6(int, Input*, int); char pad[8]; unsigned char state; };
int PropGrabbableIsThrownCondition_181cc0::vfunc_6(int, Input* input, int) {
    if (!FUN_00344e74(input, 0, &DAT_00494b44, &DAT_00494b60, 0)) return 0;
    Actor* actor = input->FUN_000592a0()->FUN_00059a30();
    Entry* entry = actor->entry;
    if (!entry) return 0;
    if (entry->kind != 5) return (unsigned)entry & ~255u;
    Object* object = entry->object;
    if (!object) return 0;
    return object->state == state;
}
