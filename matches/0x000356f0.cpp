class Obj {
    char pad[0x84];

  public:
    float value;
};
float __fastcall FUN_000356f0(Obj* self) {
    return self->value;
}