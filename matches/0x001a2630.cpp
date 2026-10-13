class Obj {
  public:
    char pad[0xb4];
    int value;
};

int __fastcall FUN_001a2630(Obj* self) {
    return self->value;
}
