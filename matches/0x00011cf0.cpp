class Obj {
  public:
    char pad[0x20];
    char mFlag;
    char GetFlag();
};
char Obj::GetFlag() {
    return mFlag;
}
