// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0025fad0 @ 0x0025fad0
struct Node { char pad[0x14]; char item[0x1c]; Node* next; void FUN_0025fad0(int value); };
int __cdecl FUN_0025f670(void* item, int* value);
void Node::FUN_0025fad0(int value) {
    if (FUN_0025f670(&item, &value)) return;
    Node* n = next;
    if (n) {
        void (Node::* volatile recurse)(int) = &Node::FUN_0025fad0;
        (n->*recurse)(value);
    }
}