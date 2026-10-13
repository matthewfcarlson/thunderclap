class Obj {
  public:
    char pad[0x40];
    int mVal;
};

int* __fastcall FUN_0015a9f0(Obj* self) {
    return &self->mVal;
}
