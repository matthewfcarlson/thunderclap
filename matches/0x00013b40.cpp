class CJointAction {
  public:
    char pad[0x1c];
    void* member1c;
    char pad20[4];
    void* member24;
    void vfunc_4();
};
struct R_13b40 {
    void call(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern R_13b40* __fastcall FUN_00059a40(void*);
void CJointAction::vfunc_4() {
    void* a = FUN_000592a0(member1c);
    R_13b40* b = FUN_00059a40(a);
    if (b)
        b->call(member24, 0);
}