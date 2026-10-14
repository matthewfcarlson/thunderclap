struct A_171c60 {
    void* FUN_000592a0();
};
struct B_171c60 {
    void* FUN_00059a30();
};
class DriftToHulkAction {
  public:
    char pad0[0x20];
    A_171c60* mAt20;
    char pad24[0x10];
    unsigned char mAt34;
    void vfunc_4();
};
void DriftToHulkAction::vfunc_4() {
    void* p = mAt20->FUN_000592a0();
    if (p) {
        p = ((B_171c60*)p)->FUN_00059a30();
        if (p)
            *(unsigned char*)((char*)p + 0x2140) = mAt34;
    }
}