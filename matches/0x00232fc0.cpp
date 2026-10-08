struct Node { char pad[0x14]; Node* parent; char pad2[8]; int value; };
int __fastcall FUN_00232fc0(Node* p) { int v; while (p) { v=p->value; if (v) return v; p=p->parent; } return 0; }