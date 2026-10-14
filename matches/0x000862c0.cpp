// Same code shape as 0x00059a30 (propagated; names are from that function)
class Obj_862c0 {
    char pad[0x10];

  public:
    unsigned int value;
};
unsigned int __fastcall FUN_00059a30(Obj_862c0* self) {
    return self->value;
}