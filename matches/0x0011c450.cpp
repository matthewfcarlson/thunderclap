extern void* g_vftable_11c450[];
void Free(void*) throw();
class Base_11c450 {
  public:
    void* vptr;
    void Fin();
};
class Obj_11c450 : public Base_11c450 {
  public:
    char pad[0x30];
    void* m34;
    ~Obj_11c450() throw();
};
Obj_11c450::~Obj_11c450() throw() {
    void* t = m34;
    vptr = g_vftable_11c450;
    Free(t);
    Fin();
}
