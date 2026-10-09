extern const float gMinusOne = -1.0f;
struct X {
    float f();
};
struct Obj {
    char pad[0xb8];
    X* value;
};
extern "C" float __fastcall FUN_00099b70(Obj* self) {
    if (self->value)
        return self->value->f();
    return gMinusOne;
}