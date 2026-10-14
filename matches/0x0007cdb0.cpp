class Obj_7cdb0 {
  public:
    void Process(int);
};
class Holder_7cdb0 {
  public:
    char pad[0xc];
    Obj_7cdb0* mObj;
};
class Thing_7cdb0 {
  public:
    char pad[0x3800];
    int* mPtr;
    char pad2[0x24];
    int mCount;
    Holder_7cdb0* mHolder;
    void Run();
    void Cleanup(int);
};
void Thing_7cdb0::Run() {
    while (mCount > 0) {
        int* p = mPtr;
        mHolder->mObj->Process(p[4]);
        if (mPtr != 0 && mPtr == p)
            Cleanup(0);
    }
}