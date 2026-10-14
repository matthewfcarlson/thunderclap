extern "C" char DAT_004279fc[];
class Sub_235620 {
  public:
    void Init();
};
class ParamValueInventoryEntity {
  public:
    virtual ParamValueInventoryEntity* vfunc_0(int);
    char pad[8];
};
extern void __cdecl thunk_FUN_00267090(ParamValueInventoryEntity*);
ParamValueInventoryEntity* ParamValueInventoryEntity::vfunc_0(int flag) {
    ParamValueInventoryEntity* self = this;
    *(unsigned long*)self = ((int)DAT_004279fc);
    ((Sub_235620*)((char*)self + 8))->Init();
    if (flag & 1)
        thunk_FUN_00267090(self);
    return self;
}