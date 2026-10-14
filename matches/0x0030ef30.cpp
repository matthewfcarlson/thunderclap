struct Blob_30ef30 {
    int d[21];
    void Fin();
    void Assign(const Blob_30ef30* o);
};
struct Src_30ef30 {
    Blob_30ef30* Get();
};
struct Obj_30ef30 {
    int p0;
    Src_30ef30* src;
    char pad[0x14 - 8];
    Blob_30ef30 cur;
    Blob_30ef30 saved;
    int state;
    Blob_30ef30* Update();
};
Blob_30ef30* Obj_30ef30::Update() {
    if (state == 1) {
        if (src) {
            Blob_30ef30 tmp = *src->Get();
            tmp.Fin();
            cur = saved;
            cur.Assign(&tmp);
        }
        state = 0;
    }
    return &cur;
}
