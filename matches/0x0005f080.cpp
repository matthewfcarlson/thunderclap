extern void* v[];
struct Base_5f080 { void BaseCtor(int); };
class ParamName_5f080 {
  public:
    void* vptr;
    char pad[12];
    int m10;
    ParamName_5f080(int a, int b) throw();
};
ParamName_5f080::ParamName_5f080(int a, int b) throw() {
    ((Base_5f080*)this)->BaseCtor(a);
    vptr = v;
    m10 = b;
}
