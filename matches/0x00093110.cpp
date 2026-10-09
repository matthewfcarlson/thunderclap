struct Obj { int slots[0x32]; };
struct Type {};
extern Type CUnlockable_RTTI_Type_Descriptor;
extern Type CUnlockableCheat_RTTI_Type_Descriptor;
extern "C" int __cdecl FUN_00344e74(void*, int, Type*, Type*, int);
float* __fastcall FUN_00093110(Obj* self, void*, int index) {
    if (index < 0 || index > 0x31) return (float*)0x3f335c;
    int result = FUN_00344e74((void*)self->slots[index], 0, &CUnlockable_RTTI_Type_Descriptor, &CUnlockableCheat_RTTI_Type_Descriptor, 0);
    if (result != 0) return (float*)(result + 0x28);
    return (float*)0x3f335c;
}