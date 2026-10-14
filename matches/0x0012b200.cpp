class C_12b200 {
  public:
    char pad[12];
    float value;
};
bool __fastcall FUN_0012b200(C_12b200* self, void*, float f) {
    self->value = f * 0.017453292f;
    return true;
}