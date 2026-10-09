class TimerSetAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual unsigned char d(int, int);
    virtual void e();
    virtual void f();
    char pad[0x18];
    void* mTimer;
    void* mThing;
};
class HelperA {
  public:
    void* run();
};
class HelperB {
  public:
    void* run();
};
unsigned char TimerSetAction::d(int, int) {
    int i = *(int*)((char*)mTimer + 0x10);
    if (i >= 0 && i < 14) {
        void* x = ((HelperA*)mThing)->run();
        x = ((HelperB*)x)->run();
        *(int*)((char*)x + 0x1e60 + i * 4) = *(int*)((char*)mTimer + 0x14);
    }
    return 0;
}