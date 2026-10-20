// Same code shape as 0x00275390 (propagated; names are from that function)
struct Base_275750 {
    virtual void Run();
    int dummy;
    Base_275750(int x);
};
struct DriveMediaRequest_275750 : Base_275750 {
    int b;
    int value;
    DriveMediaRequest_275750(int x, int y);
};
void FinishInit();
DriveMediaRequest_275750::DriveMediaRequest_275750(int x, int y) : Base_275750(x) {
    value = y;
    FinishInit();
}
