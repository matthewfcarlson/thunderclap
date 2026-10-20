// Same code shape as 0x00275390 (propagated; names are from that function)
struct Base_275430 {
    virtual void Run();
    int dummy;
    Base_275430(int x);
};
struct FileGetPositionRequest_275430 : Base_275430 {
    int b;
    int value;
    FileGetPositionRequest_275430(int x, int y);
};
void FinishInit();
FileGetPositionRequest_275430::FileGetPositionRequest_275430(int x, int y) : Base_275430(x) {
    value = y;
    FinishInit();
}
