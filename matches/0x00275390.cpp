struct Base_275390 {
    virtual void Run();
    int dummy;
    Base_275390(int x);
};
struct FileSetPositionRequest : Base_275390 {
    int b;
    int value;
    FileSetPositionRequest(int x, int y);
};
void FinishInit();
FileSetPositionRequest::FileSetPositionRequest(int x, int y) : Base_275390(x) {
    value = y;
    FinishInit();
}
