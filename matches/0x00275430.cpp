// Same code shape as 0x00275390 (propagated; names are from that function)
struct FileRequest_275430 {
    virtual void Run();
    int dummy;
    FileRequest_275430(int x);
};
struct FileGetPositionRequest_275430 : FileRequest_275430 {
    int b;
    int value;
    FileGetPositionRequest_275430(int x, int y);
};
void FinishInit();
FileGetPositionRequest_275430::FileGetPositionRequest_275430(int x, int y) : FileRequest_275430(x) {
    value = y;
    FinishInit();
}
