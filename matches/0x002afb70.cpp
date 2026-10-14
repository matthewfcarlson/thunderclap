extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2afb70[];
void operator delete(void*);
class Base_2afb70 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2afb70 : public Base_2afb70 {
  public:
    char pad[0xc];
    void* m10;
    void* m14;
    void* m18;
    ~Obj_2afb70();
};
Obj_2afb70::~Obj_2afb70() {
    vptr = g_vftable_2afb70;

    operator delete(m14);
    operator delete(m18);
    Fin();
}
