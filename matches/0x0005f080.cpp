extern void* v[];
extern "C" void __stdcall BaseCtor(int);
class Obj {
  public:
    void* vptr;
    char pad[12];
    int m10;
    Obj(int a, int b) throw();
};
Obj::Obj(int a, int b) throw() {
    BaseCtor(a);
    vptr = v;
    m10 = b;
}
