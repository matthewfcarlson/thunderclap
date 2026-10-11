extern "C" char DAT_0042ae14[];
class HalRsdFileStream {
  public:
    char pad[0x24];
    char* mHeader;
    char* vfunc_9(int);
};
char* HalRsdFileStream::vfunc_9(int index) {
    if (!mHeader)
        return (char*)((int)DAT_0042ae14);
    return mHeader + index * 16 + 0xa4;
}