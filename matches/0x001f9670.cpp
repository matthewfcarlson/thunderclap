struct Obj {
    char pad[0x20];
    unsigned short value;
};
struct Sub {
    int Find(int (*cb)(), void*);
};
struct Temp {
    void Cleanup();
};
struct Receiver {
    char pad[0xc6c];
    Sub* sub;
    bool Target(int a, int b, int c, int d, unsigned short v);
};
extern int Callback();
bool Receiver::Target(int a, int b, int c, int d, unsigned short v) {
    int r = sub->Find(Callback, &a);
    if (!r) {
        ((Temp*)&a)->Cleanup();
        return false;
    }
    ((Obj*)r)->value = v;
    ((Temp*)&a)->Cleanup();
    return true;
}