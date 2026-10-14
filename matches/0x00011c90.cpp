class Obj_11c90 {
  public:
    char pad[0x1e58];
    float value;
    float Get() { return value; }
};

float __fastcall FUN_00011c90(Obj_11c90* self) {
    return self->Get();
}
