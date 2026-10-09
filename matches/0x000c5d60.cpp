struct Obj {
    Obj* Make(int);
    void Check(int*);
};
bool Target(Obj* obj, int index) {
    int local[41];
    for (int i = 0; i < 1; ++i) {
        Obj* p = obj->Make(i);
        p->Check(local);
        if (local[index * 3] == 1)
            return true;
    }
    return false;
}