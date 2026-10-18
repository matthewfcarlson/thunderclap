struct B_1c4ea0 {
    void Fn(int);
};

struct A_1c4ea0 {
    char pad[8];
    B_1c4ea0 b;
    void Forward(int);
};

void A_1c4ea0::Forward(int a0) {
    b.Fn(a0);
}
