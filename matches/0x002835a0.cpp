class Ref { public: virtual void A(); virtual void B(); };
struct Slot { Ref* p; char pad[0x18]; };
class CDecalQueue { public: virtual void A(); CDecalQueue(); ~CDecalQueue(); void Init(); void Tail(); char pad[0x34]; Slot items[100]; };
CDecalQueue::~CDecalQueue() {
 Init();
 for (int i=0;i<100;i++) { if (items[i].p) { items[i].p->B(); items[i].p=0; } }
 Tail();
}