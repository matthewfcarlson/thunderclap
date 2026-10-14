class Obj_2c7210 {
  public:
    char pad[8];
    unsigned flags;
    char pad2[8];
    void* value;
};
void __cdecl cleanup(void*);
void __fastcall FUN_002c7210(Obj_2c7210* self) {
    cleanup(self->value);
    self->value = 0;
    self->flags &= ~0x20u;
}