extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22a950[];
extern int g_count_22a950;
void operator delete(void*);
class Base_22a950 {
  public:
    void* vptr;
    void Fin();
};
class Obj_22a950 : public Base_22a950 {
  public:
    Obj_22a950* f2(unsigned char flags);
};
Obj_22a950* Obj_22a950::f2(unsigned char flags) {
    vptr = g_vftable_22a950;
    _ReadWriteBarrier();
    g_count_22a950--;
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
