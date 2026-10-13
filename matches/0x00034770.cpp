class Obj {
  public:
    char pad[0x2f8];
    unsigned char value;
    unsigned char Get() { return value; }
};
unsigned char __fastcall FUN_00034770(Obj* self) {
    return self->Get();
}
