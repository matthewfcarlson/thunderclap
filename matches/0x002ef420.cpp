extern const float gOne_2ef420;
struct Inner_2ef420 {
    char pad[0x34];
    float value;
};
struct Holder_2ef420 {
    char pad[0x20];
    Inner_2ef420* inner;
};
struct Obj_2ef420 {
    char pad[0x74];
    Holder_2ef420* holder;
};
float __fastcall FUN_002ef420(Obj_2ef420* self) {
    if (self->holder)
        return self->holder->inner->value;
    return gOne_2ef420;
}
