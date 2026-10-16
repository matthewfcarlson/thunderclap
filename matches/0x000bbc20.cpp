class Timer {
  public:
    void Set(int);
};
class Obj {
  public:
    char pad[0x50];
    Timer* timer;
};
class Owner {
  public:
    void* v;
    Obj* obj;
    int Run(int a, int b);
};
int Owner::Run(int a, int b) {
    if (!obj)
        return -1;
    Timer* t = obj->timer;
    if (t)
        t->Set(50000);
    return 0;
}