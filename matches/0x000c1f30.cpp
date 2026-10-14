struct Sub {
    int G();
};

struct Obj {
    char pad[4];
    Sub* m;
    int F(int a, int b);
};

int Obj::F(int a, int b) {
    if (!m)
        return -1;
    m->G();
    return 0;
}
