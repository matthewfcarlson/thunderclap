class Inner {
  public:
    void Work(void*, int);
};
class Obj {
  public:
    char pad[0xb8];
    Inner* p;
    void Fn(int x);
};
extern void* global;
void Obj::Fn(int x) {
    if (p)
        p->Work(global, x);
}