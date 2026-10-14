struct S {
    char pad[0x38];
    float value;
};
bool __fastcall FUN_00068a30(S* self, void* notUsed, float degrees) {
    self->value = degrees * 0.017453292f;
    return true;
}
