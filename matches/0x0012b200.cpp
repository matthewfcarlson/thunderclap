class C {
  public:
    char pad[12];
    float value;
};
bool __fastcall FUN_0012b200(C* self, void*, float f) {
    self->value = f * 0.017453292f;
    return true;
}