struct Sub_c1f30 {
    int G();
};

struct Obj_c1f30 {
    char pad[4];
    Sub_c1f30* m;
    int F(int a, int b);
};

int Obj_c1f30::F(int a, int b) {
    if (!m)
        return -1;
    m->G();
    return 0;
}
