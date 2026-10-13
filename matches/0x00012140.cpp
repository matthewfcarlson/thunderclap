class Obj {
  public:
    char mBuf[0x50];
    char* Get();
};
char* Obj::Get() {
    return (char*)((char*)mBuf + 0x50);
}