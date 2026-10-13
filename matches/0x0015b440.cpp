class Obj {
  public:
    char pad[0x40];
    char* Get() { return pad + 0x40; }
};

char* FUN_0015b440(Obj* self) {
    return self->Get();
}