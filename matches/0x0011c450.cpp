extern void* g_vftable[];
void Free(void*) throw();
class Base {
  public:
    void* vptr;
    void Fin();
};
class Obj : public Base {
  public:
    char pad[0x30];
    void* m34;
    ~Obj() throw();
};
Obj::~Obj() throw() {
    void* t = m34;
    vptr = g_vftable;
    Free(t);
    Fin();
}
