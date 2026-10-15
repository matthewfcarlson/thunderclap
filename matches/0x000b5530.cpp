extern "C" void* __cdecl FUN_000fc260(const char*);
class Record {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char pad[0x14];
    char data[4];
};
class Owner {
  public:
    void process(void*, int, int, int, int, int, int, int);
    void target(int a, int b, int c, int d, int e, int f, int g);
};
void Owner::target(int a, int b, int c, int d, int e, int f, int g) {
    Record* r = (Record*)FUN_000fc260("side_mission_success_record");
    if (r && &r->data) {
        process(&r->data, a, b, c, d, e, f, g);
        r->f3();
    }
}