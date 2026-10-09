class Target {
    char pad[0x14];

  public:
    unsigned char value;
};
unsigned char __fastcall FUN_00083d10(Target* self) {
    return self->value;
}