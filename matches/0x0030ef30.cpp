struct Blob {
    int d[21];
    void Fin();
    void Assign(const Blob* o);
};
struct Src {
    Blob* Get();
};
struct Obj {
    int p0;
    Src* src;
    char pad[0x14 - 8];
    Blob cur;
    Blob saved;
    int state;
    Blob* Update();
};
Blob* Obj::Update() {
    if (state == 1) {
        if (src) {
            Blob tmp = *src->Get();
            tmp.Fin();
            cur = saved;
            cur.Assign(&tmp);
        }
        state = 0;
    }
    return &cur;
}
