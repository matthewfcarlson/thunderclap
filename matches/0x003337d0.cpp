class T_3337d0 {
  public:
    char pad[0x48];
    char mFlag;
    void Set(void* p);
    void FUN_003335e0();
};
void T_3337d0::Set(void* p) {
    mFlag = (p != 0);
    FUN_003335e0();
}
