struct Node {
    Node* next;
};
Node* __cdecl target(Node* p) {
    Node* end = (Node*)((char*)p + 0x1c);
    Node* cur = *(Node**)((char*)p + 0x18);
    if (cur == end)
        return 0;
    while (cur->next != end)
        cur = cur->next;
    return cur;
}