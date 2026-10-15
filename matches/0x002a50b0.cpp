// Same code shape as 0x00059a30 (propagated; names are from that function)
class Obj_2a50b0 {
    char pad[0x10];

  public:
    unsigned int value;
};
unsigned int __fastcall FUN_002a50b0(Obj_2a50b0* self) {
    return self->value;
}