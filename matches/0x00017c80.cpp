// Same code shape as 0x00013b40 (propagated; names are from that function)
class CSnapToWallAction {
  public:
    char pad[0x1c];
    void* member1c;
    char pad20[4];
    void* member24;
    void vfunc_4();
};
struct R_17c80 {
    void call(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern R_17c80* __fastcall FUN_00059a40(void*);
void CSnapToWallAction::vfunc_4() {
    void* a = FUN_000592a0(member1c);
    R_17c80* b = FUN_00059a40(a);
    if (b)
        b->call(member24, 0);
}