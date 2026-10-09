class Node { public: virtual void f0(); virtual void f1(); virtual void Call(void*); Node* next; };
class Owner { public: Node* head; void Walk(void*); };
void Owner::Walk(void* arg) { for (Node* p = head; p; p = p->next) p->Call(arg); }