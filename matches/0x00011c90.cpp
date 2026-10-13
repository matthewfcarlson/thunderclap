class Obj {
  public:
    char pad[0x1e58];
    float value;
    float Get() { return value; }
};

float __fastcall FUN_00011c90(Obj* self) {
    return self->Get();
}
