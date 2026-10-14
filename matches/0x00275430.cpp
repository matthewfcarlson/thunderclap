// Same code shape as 0x00275390 (propagated; names are from that function)
struct Base_275430 {
    virtual void Run();
    int dummy;
    Base_275430(int x);
};
struct FileSetPositionRequest : Base_275430 {
    int b;
    int value;
    FileSetPositionRequest(int x, int y);
};
void FinishInit();
FileSetPositionRequest::FileSetPositionRequest(int x, int y) : Base_275430(x) {
    value = y;
    FinishInit();
}
