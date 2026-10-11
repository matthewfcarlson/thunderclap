extern "C" char DAT_00431de4[];
class Helper {
  public:
    void Init();
};
class PhysicsJoint {
  public:
    char pad[0x20];
    int m20;
    int m24;
};
extern void __cdecl AddRef(void*);
void __fastcall Target(PhysicsJoint* self) {
    *(int*)self = ((int)DAT_00431de4);
    ((Helper*)((char*)self + 0x64))->Init();
    ((Helper*)((char*)self + 0x48))->Init();
    int value = self->m20;
    self->m24 = value;
    if (value)
        AddRef((void*)value);
}