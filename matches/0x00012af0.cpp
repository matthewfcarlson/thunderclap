class C_12af0 {
  public:
    char pad[0x18];
    int mValue;
    int* GetValue() { return &mValue; }
};
int* __fastcall FUN_00012af0(C_12af0* self) {
    return self->GetValue();
}