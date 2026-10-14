struct Node {
    Node* next;
};
int Count(Node** p) {
    int n = 0;
    Node* cur = *p;
    while (cur) {
        cur = cur->next;
        n++;
    }
    return n;
}
