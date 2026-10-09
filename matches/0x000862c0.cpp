// Same code shape as 0x00059a30 (propagated; names are from that function)
class Obj {
    char pad[0x10];

  public:
    unsigned int value;
};
unsigned int __fastcall FUN_00059a30(Obj* self) {
    return self->value;
}