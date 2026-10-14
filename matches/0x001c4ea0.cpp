struct B_1c4ea0 {
    void Fn();
};

struct A_1c4ea0 {
    char pad[8];
    B_1c4ea0 b;
    void Forward();
};

void A_1c4ea0::Forward() {
    b.Fn();
}
