extern "C" void* __cdecl Find(const char*);
class Result {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char data[20];
    int member;
};
class Owner {
  public:
    void Apply(void*, int, int, int, int, int, int, int);
    void Run(int, int, int, int, int, int, int);
};
void Owner::Run(int a, int b, int c, int d, int e, int f, int g) {
    Result* r = (Result*)Find("side_mission_success_result");
    if (r && &r->member) {
        Apply(&r->member, a, b, c, d, e, f, g);
        r->f3();
    }
}