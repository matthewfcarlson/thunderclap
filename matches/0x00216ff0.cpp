struct Node {
    Node* next;
    unsigned char pad[1];
    unsigned char flags;
    unsigned char pad2[2];
    Node* data;
    unsigned char rest[0x3c];
    Node* child;
};
struct Obj_216ff0 {
    unsigned char pad[0x5c];
    Node* head;
};
extern "C" void __cdecl FUN_002164b0(void *, void *);
extern "C" void FUN_00216ff0(void * obj) {
    Node* outer = ((Obj_216ff0 *)obj)->head;
    while (outer) {
        if (outer->flags & 3) {
            Node* inner = outer->child;
            while (inner) {
                if ((inner->flags & 7) == 0) {
                    Node* p = inner->data;
                    if (*(int*)p >= 4) {
                        Node* q = *(Node**)((char*)p + 4);
                        if (q->flags & 3)
                            FUN_002164b0((Obj_216ff0 *)((Obj_216ff0 *)obj), (Node *)q);
                    }
                }
                inner = inner->next;
            }
        }
        outer = outer->next;
    }
}