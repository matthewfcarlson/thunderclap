// Same code shape as 0x001d1a50 (propagated; names are from that function)
typedef unsigned int u32_1d1ac0;
void FUN_002133d0(u32_1d1ac0, u32_1d1ac0);
class C_1d1ac0 {
  public:
    char pad[8];
    u32_1d1ac0 member;
    bool target(u32_1d1ac0 arg);
};
bool C_1d1ac0::target(u32_1d1ac0 arg) {
    FUN_002133d0(member, arg);
    return true;
}