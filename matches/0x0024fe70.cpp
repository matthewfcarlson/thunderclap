extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Base {
  public:
    void* vptr;
    ~Base() throw();
};
class SeqEventContainer : public Base {
  public:
    char pad[4];
    int m8;
    int mc;
    int m10;
    SeqEventContainer();
};
SeqEventContainer::SeqEventContainer() {
    Base::~Base();
    int* q = &m8;
    *q = 0;
    vptr = g_vftable;
    _ReadWriteBarrier();
    mc = 0;
    m10 = 0;
}
