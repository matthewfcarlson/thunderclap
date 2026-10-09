class HalRsdFileStream {
  public:
    char pad[0x24];
    char* mHeader;
    char* vfunc_9(int);
};
char* HalRsdFileStream::vfunc_9(int index) {
    if (!mHeader)
        return (char*)0x42ae14;
    return mHeader + index * 16 + 0xa4;
}