struct Obj_c5d60 {
    Obj_c5d60* Make(int);
    void Check(int*);
};
bool Target(Obj_c5d60* obj, int index) {
    int local[41];
    for (int i = 0; i < 1; ++i) {
        Obj_c5d60* p = obj->Make(i);
        p->Check(local);
        if (local[index * 3] == 1)
            return true;
    }
    return false;
}