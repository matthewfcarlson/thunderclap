struct Node {
    Node* next;
    Node* previous;
};

extern Node* DAT_0052a17c;
extern Node* DAT_0052a180;
extern char DAT_0052a188;
extern void(__stdcall* DAT_003f2c8c)(void*);
extern void(__stdcall* DAT_003f2c88)(void*);

void __cdecl FUN_0026d940(Node* node) {
    DAT_003f2c8c(&DAT_0052a188);
    if (node->previous == 0)
        DAT_0052a180 = node->next;
    else
        node->previous->next = node->next;
    if (node->next == 0)
        DAT_0052a17c = node->previous;
    else
        node->next->previous = node->previous;
    DAT_003f2c88(&DAT_0052a188);
}