extern void* v[];
struct Base_5f080 { void BaseCtor(int); };
class Obj {
  public:
    void* vptr;
    char pad[12];
    int m10;
    Obj(int a, int b) throw();
};
Obj::Obj(int a, int b) throw() {
    ((Base_5f080*)this)->BaseCtor(a);
    vptr = v;
    m10 = b;
}
