class Obj_15b440 {
  public:
    char pad[0x40];
    char* Get() { return pad + 0x40; }
};

char* FUN_0015b440(Obj_15b440* self) {
    return self->Get();
}