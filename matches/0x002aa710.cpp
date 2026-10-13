class Obj {
  public:
    char pad[0x2c];
    int value;
};
int __fastcall FUN_002aa710(Obj* self) {
    return self->value;
}
