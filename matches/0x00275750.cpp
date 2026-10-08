// Same code shape as 0x00275390 (propagated; names are from that function)
struct Base {
    virtual void Run();
    int dummy;
    Base(int x);
};
struct FileSetPositionRequest : Base {
    int b;
    int value;
    FileSetPositionRequest(int x, int y);
};
void FinishInit();
FileSetPositionRequest::FileSetPositionRequest(int x, int y) : Base(x) {
    value = y;
    FinishInit();
}
