class Obj {
  public:
    char pad[0x10];
    int mValue;
};
int* __fastcall FUN_001e8b00(Obj* self) {
    return &self->mValue;
}