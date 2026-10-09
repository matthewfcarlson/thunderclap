extern const float zero;
class Obj {
    char pad[0x1b18];

  public:
    float value;
    int count;
};
bool __fastcall FUN_00036170(Obj* self) {
    if (self->value > zero)
        return true;
    return self->count > 0;
}