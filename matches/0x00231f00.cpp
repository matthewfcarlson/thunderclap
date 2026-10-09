class Node { public: char pad[8]; Node* next; void F(int, int); };
class Owner { public: char pad[0x20]; Node* head; void Run(); };
void Owner::Run() { Node* n = head; while (n) { n->F(8, 1); n = n->next; } }