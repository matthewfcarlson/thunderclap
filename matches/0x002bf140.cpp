// Same code shape as 0x00059a30 (propagated; names are from that function)
class Obj_2bf140 {
    char pad[0x10];

  public:
    unsigned int value;
};
unsigned int __fastcall FUN_002bf140(Obj_2bf140* self) {
    return self->value;
}