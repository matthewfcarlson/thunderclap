class C_1cc860 {
    char pad[0x1198];

  public:
    float Get() { return *(float*)((char*)this + 0x1198); }
};

float __fastcall FUN_001cc860(C_1cc860* self) {
    return self->Get();
}
