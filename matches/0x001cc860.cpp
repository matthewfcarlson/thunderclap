class C {
    char pad[0x1198];

  public:
    float Get() { return *(float*)((char*)this + 0x1198); }
};

float __fastcall FUN_001cc860(C* self) {
    return self->Get();
}
