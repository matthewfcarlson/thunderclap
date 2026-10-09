// Same code shape as 0x00236ee0 (propagated; names are from that function)
class Node { public: virtual void f0(); virtual void f1(void*); Node* next; };
class Owner { public: Node* head; void run(void*); };
void Owner::run(void* arg) { for (Node* p = head; p != 0; p = p->next) p->f1(arg); }