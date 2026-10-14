typedef unsigned int u32_1d1a50;
void FUN_002133d0(u32_1d1a50, u32_1d1a50);
class C_1d1a50 {
  public:
    char pad[8];
    u32_1d1a50 member;
    bool target(u32_1d1a50 arg);
};
bool C_1d1a50::target(u32_1d1a50 arg) {
    FUN_002133d0(member, arg);
    return true;
}