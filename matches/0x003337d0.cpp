void __fastcall FUN_003335e0();
class T {
  public:
    char pad[0x48];
    char mFlag;
    void Set(void* p);
};
void T::Set(void* p) {
    mFlag = (p != 0);
    FUN_003335e0();
}
