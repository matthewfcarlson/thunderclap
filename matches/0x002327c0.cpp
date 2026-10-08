struct Node { Node* next; char pad[12]; };
int __fastcall FUN_002327c0(Node** p) {
    int n = 0;
    Node* cur = *p;
    while (cur) {
        ++n;
        cur = *(Node**)((char*)cur + 0x10);
    }
    return n;
}