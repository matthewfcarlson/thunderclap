// Same code shape as 0x00092050 (propagated; names are from that function)
class C {
  public:
    char pad[0x38];
};
C* __fastcall FUN_00092050(C* p) {
    return (C*)((char*)p + 0x38);
}