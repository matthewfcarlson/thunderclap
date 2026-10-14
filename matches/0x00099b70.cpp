extern const float gMinusOne_99b70 = -1.0f;
struct X_99b70 {
    float f();
};
struct Obj_99b70 {
    char pad[0xb8];
    X_99b70* value;
};
extern "C" float __fastcall FUN_00099b70(Obj_99b70* self) {
    if (self->value)
        return self->value->f();
    return gMinusOne_99b70;
}