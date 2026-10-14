struct Inner {
    char pad[0x24];
    int value;
    void Check();
};

struct Obj {
    char pad[0x70];
    Inner* p;
    void Fn();
};

void Obj::Fn() {
    if (p != 0 && p->value == 2) {
        p->Check();
    }
}
