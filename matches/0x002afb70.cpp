extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2afb70[];
void operator delete(void*);
class Entity_2afb70 {
  public:
    void* vptr;
    void Fin();
};
class Expression_2afb70 : public Entity_2afb70 {
  public:
    char pad[0xc];
    void* m10;
    void* m14;
    void* m18;
    ~Expression_2afb70();
};
Expression_2afb70::~Expression_2afb70() {
    vptr = g_vftable_2afb70;

    operator delete(m14);
    operator delete(m18);
    Fin();
}
