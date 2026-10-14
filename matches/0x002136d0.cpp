struct Payload_2136d0 {
    char pad[8];
    int v;
};
struct Node {
    int type;
    Payload_2136d0* payload;
};
struct Buf_2136d0 {
    char pad[8];
    int* cursor;
};

Node* __fastcall readNode(void* a, int* b);

int __cdecl FUN_002136d0(Buf_2136d0* p1, void* p2) {
    Node* node = readNode(p2, (int*)p1);
    int val;
    switch (node->type) {
    case 5:
        val = node->payload->v;
        break;
    case 7:
        val = node->payload->v;
        break;
    default:
        return 0;
    }
    if (val == 0) {
        return 0;
    }
    int* cur = p1->cursor;
    cur[1] = val;
    cur[0] = 5;
    p1->cursor += 2;
    return 1;
}
