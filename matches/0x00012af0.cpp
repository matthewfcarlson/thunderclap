class C {
  public:
    char pad[0x18];
    int mValue;
    int* GetValue() { return &mValue; }
};
int* __fastcall FUN_00012af0(C* self) {
    return self->GetValue();
}