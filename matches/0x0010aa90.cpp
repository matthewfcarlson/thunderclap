struct State {
    void FUN_00025260(int, int, int);
    void FUN_000253c0(int);
};
struct Input {
    char pad[0x20];
    State* state;
};
struct Flag {
    char pad[0x72];
    unsigned char enabled;
};
struct Node {
    char pad[0x74];
    Flag* flag;
};
struct Link {
    Node* FUN_001d72e0();
};
struct Object {
    char pad[0x128];
    Link* link;
    void FUN_000368d0(int);
};
struct Manager {
    void FUN_001dcf60(int);
};
struct Global {
    char pad[0xc];
    Manager* manager;
};
extern Global* DAT_004dd700;
struct Target {
    unsigned char FUN_00109df0(Input*, int, int, int, int, int, int, int);
    unsigned char run(Input*, int, int, int, int, int, int, Object*, int, int, int);
};
unsigned char Target::run(Input* input, int a2, int a3, int a4, int a5, int a6, int a7, Object* obj, int a9,
                          int a10, int a11) {
    input->state->FUN_00025260(a10, 0, 0);
    input->state->FUN_000253c0(a11);
    DAT_004dd700->manager->FUN_001dcf60(a11);
    Link* link = obj->link;
    if (link && link->FUN_001d72e0()) {
        Node* node = link->FUN_001d72e0();
        Flag* flag = node->flag;
        if (flag)
            flag->enabled = 0;
    }
    obj->FUN_000368d0(0);
    unsigned char result = FUN_00109df0(input, a2, a3, a4, a5, a6, a7, a9);
    input->state->FUN_00025260(1, 0, 0);
    input->state->FUN_000253c0(1);
    DAT_004dd700->manager->FUN_001dcf60(1);
    return result;
}