// Same code shape as 0x00013b40 (propagated; names are from that function)
class CMoveAction {
  public:
    char pad[0x1c];
    void* member1c;
    char pad20[4];
    void* member24;
    void vfunc_4();
};
struct R_14e60 {
    void call(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern R_14e60* __fastcall FUN_00059a40(void*);
void CMoveAction::vfunc_4() {
    void* a = FUN_000592a0(member1c);
    R_14e60* b = FUN_00059a40(a);
    if (b)
        b->call(member24, 0);
}