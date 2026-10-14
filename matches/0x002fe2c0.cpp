struct Inner_2fe2c0 {
    char pad[0x24];
    int value;
    void Check();
};

struct Obj_2fe2c0 {
    char pad[0x70];
    Inner_2fe2c0* p;
    void Fn();
};

void Obj_2fe2c0::Fn() {
    if (p != 0 && p->value == 2) {
        p->Check();
    }
}
