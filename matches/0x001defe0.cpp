struct Obj {
    char pad[0xa8];
    char flag;
};
struct Holder {
    char pad[0x11c];
    Obj* obj;
};
struct ThisWrap_001defe0 {
    Holder* get(int);
    void FUN_001defe0(int id, char v);
};
void ThisWrap_001defe0::FUN_001defe0(int id, char v) {
    Holder* h = this->get(id);
    if (h) {
        Obj* o = h->obj;
        if (o)
            o->flag = v;
    }
}