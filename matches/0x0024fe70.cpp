extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class SeqEvent_24fe70 {
  public:
    void* vptr;
    ~SeqEvent_24fe70() throw();
};
class SeqEventContainer : public SeqEvent_24fe70 {
  public:
    char pad[4];
    int m8;
    int mc;
    int m10;
    SeqEventContainer();
};
SeqEventContainer::SeqEventContainer() {
    SeqEvent_24fe70::~SeqEvent_24fe70();
    int* q = &m8;
    *q = 0;
    vptr = g_vftable;
    _ReadWriteBarrier();
    mc = 0;
    m10 = 0;
}
