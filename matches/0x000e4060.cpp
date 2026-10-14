struct Worker_e4060 {
    int* Find(void*);
};
struct Z {
    char pad[8];
    Worker_e4060* w;
};
struct Y_e4060 {
    char pad[4];
    Z* z;
};
struct X_e4060 {
    char pad[8];
    Y_e4060* y;
};
class Owner_e4060 {
  public:
    char pad[0x14];
    X_e4060* mA;
    char pad2[0x294];
    int* slot;
    void Update(void* arg);
};
void Owner_e4060::Update(void* arg) {
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
