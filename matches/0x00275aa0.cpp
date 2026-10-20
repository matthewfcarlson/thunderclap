// Same code shape as 0x00275390 (propagated; names are from that function)
struct Base_275aa0 {
    virtual void Run();
    int dummy;
    Base_275aa0(int x);
};
struct DriveFindNextRequest_275aa0 : Base_275aa0 {
    int b;
    int value;
    DriveFindNextRequest_275aa0(int x, int y);
};
void FinishInit();
DriveFindNextRequest_275aa0::DriveFindNextRequest_275aa0(int x, int y) : Base_275aa0(x) {
    value = y;
    FinishInit();
}
