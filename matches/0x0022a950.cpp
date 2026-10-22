extern "C" void _ReadWriteBarrier();
extern void* g_vftable_22a950[];
extern int g_count_22a950;
void operator delete(void*);
class Entity_22a950 {
  public:
    void* vptr;
    void Fin();
};
class Driver_22a950 : public Entity_22a950 {
  public:
    Driver_22a950* f2(unsigned char flags);
};
Driver_22a950* Driver_22a950::f2(unsigned char flags) {
    vptr = g_vftable_22a950;
    _ReadWriteBarrier();
    g_count_22a950--;
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
