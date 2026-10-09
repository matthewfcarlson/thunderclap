class Target {
    char pad[0x14a9];

  public:
    unsigned char value;
};
unsigned char __fastcall FUN_001cd010(Target* self) {
    return self->value;
}