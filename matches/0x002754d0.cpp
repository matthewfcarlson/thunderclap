// Same code shape as 0x00275390 (propagated; names are from that function)
struct Base_2754d0 {
    virtual void Run();
    int dummy;
    Base_2754d0(int x);
};
struct FileGetSizeRequest_2754d0 : Base_2754d0 {
    int b;
    int value;
    FileGetSizeRequest_2754d0(int x, int y);
};
void FinishInit();
FileGetSizeRequest_2754d0::FileGetSizeRequest_2754d0(int x, int y) : Base_2754d0(x) {
    value = y;
    FinishInit();
}
