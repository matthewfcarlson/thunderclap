// Same code shape as 0x00275390 (propagated; names are from that function)
struct Base_275750 {
    virtual void Run();
    int dummy;
    Base_275750(int x);
};
struct FileSetPositionRequest : Base_275750 {
    int b;
    int value;
    FileSetPositionRequest(int x, int y);
};
void FinishInit();
FileSetPositionRequest::FileSetPositionRequest(int x, int y) : Base_275750(x) {
    value = y;
    FinishInit();
}
