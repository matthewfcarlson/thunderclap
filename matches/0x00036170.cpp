extern const float zero_36170;
class Obj_36170 {
    char pad[0x1b18];

  public:
    float value;
    int count;
};
bool __fastcall FUN_00036170(Obj_36170* self) {
    if (self->value > zero_36170)
        return true;
    return self->count > 0;
}