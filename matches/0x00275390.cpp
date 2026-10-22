struct FileRequest_275390 {
    virtual void Run();
    int dummy;
    FileRequest_275390(int x);
};
struct FileSetPositionRequest : FileRequest_275390 {
    int b;
    int value;
    FileSetPositionRequest(int x, int y);
};
void FinishInit();
FileSetPositionRequest::FileSetPositionRequest(int x, int y) : FileRequest_275390(x) {
    value = y;
    FinishInit();
}
