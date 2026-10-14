struct Transition {
    char data[28];
    void FUN_001cac80(int oldState, int newState);
};
struct Queue {
    void FUN_001cbc20(Transition*);
};
struct Global {
    char pad[0x30];
    Queue* queue;
};
extern Global* DAT_004dd700;
struct Item {
    void FUN_000bd1b0(int);
};
struct Holder {
    Item* FUN_00086280();
};
struct Actor {
    char pad0[0x588];
    Holder* holder;
    char pad1[0x10];
    int state;
    int previous;
    unsigned char flags[0x400];
    char pad2[0x148];
    void* pending;
    int FUN_00203cd0();
    bool FUN_00208040(int, int);
    void FUN_00203e30(void*);
    void FUN_00207410();
    bool FUN_00208920();
};
bool Actor::FUN_00208920() {
    bool result = false;
    int next = FUN_00203cd0();
    if (!next)
        return false;
    if (next != state) {
        Transition transition;
        transition.FUN_001cac80(state, next);
        DAT_004dd700->queue->FUN_001cbc20(&transition);
        result = FUN_00208040(state, next);
        if (next < 0 || next >= 0x400 || (flags[next] != 1 && flags[next] != 3)) {
            result = true;
            Item* item = holder->FUN_00086280();
            if (item)
                item->FUN_000bd1b0(0);
            if (pending) {
                FUN_00203e30(pending);
                FUN_00207410();
            }
        }
        previous = state;
        state = next;
    }
    return result;
}