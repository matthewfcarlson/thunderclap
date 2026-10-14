class Obj_12140 {
  public:
    char mBuf[0x50];
    char* Get();
};
char* Obj_12140::Get() {
    return (char*)((char*)mBuf + 0x50);
}