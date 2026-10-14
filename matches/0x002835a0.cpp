class Ref_2835a0 {
  public:
    virtual void A();
    virtual void B();
};
struct Slot_2835a0 {
    Ref_2835a0* p;
    char pad[0x18];
};
class CDecalQueue {
  public:
    virtual void A();
    CDecalQueue();
    ~CDecalQueue();
    void Init();
    void Tail();
    char pad[0x34];
    Slot_2835a0 items[100];
};
CDecalQueue::~CDecalQueue() {
    Init();
    for (int i = 0; i < 100; i++) {
        if (items[i].p) {
            items[i].p->B();
            items[i].p = 0;
        }
    }
    Tail();
}