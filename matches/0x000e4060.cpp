struct Worker {
    int* Find(void*);
};
struct Z {
    char pad[8];
    Worker* w;
};
struct Y {
    char pad[4];
    Z* z;
};
struct X {
    char pad[8];
    Y* y;
};
class Owner {
  public:
    char pad[0x14];
    X* mA;
    char pad2[0x294];
    int* slot;
    void Update(void* arg);
};
void Owner::Update(void* arg) {
    int* p = mA->y->z->w->Find(arg);
    slot = p;
    if (p) {
        int i = 0;
        int* q = p + 1;
        do {
            if (*q == 0)
                break;
            ++i;
            ++q;
        } while (i < 4);
        if (i != 4)
            p[i + 1] = (int)this;
    }
}
