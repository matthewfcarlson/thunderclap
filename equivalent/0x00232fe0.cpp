// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00232fe0 @ 0x00232fe0
struct Node { char pad0[0x14]; Node* parent; char pad18[4]; Node* boundary; Node* value; Node* FUN_00232fe0(); }; Node* Node::FUN_00232fe0() { if (boundary) return boundary; Node* node = this; while (node) { if (node->value) return node->value; node = node->parent; } return 0; }