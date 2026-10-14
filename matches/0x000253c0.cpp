// Same code shape as 0x00025370 (propagated; names are from that function)
struct Ctx_253c0 {
    int pad[17];
    int Find(int);
};
struct Act_253c0 {
    int pad;
    void Do(int);
};
struct Target_253c0 {
    int* vt;
    int pad[2];
    int count;
    int items[1];
    void Run(int arg);
};
void Target_253c0::Run(int arg) {
    int i = 0;
    while (i < count) {
        Ctx_253c0* c = (Ctx_253c0*)vt[17];
        int r = c->Find(items[i]);
        if (r)
            ((Act_253c0*)r)->Do(arg);
        ++i;
    }
}
