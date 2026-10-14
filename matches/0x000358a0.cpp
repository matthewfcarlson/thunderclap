struct Obj_358a0 {
    char pad[0x1e4];
    float value;
};
extern const float zero_358a0;
int __fastcall target(Obj_358a0* self) {
    return self->value > zero_358a0;
}