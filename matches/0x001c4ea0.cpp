struct B {
    void Fn();
};

struct A {
    char pad[8];
    B b;
    void Forward();
};

void A::Forward() {
    b.Fn();
}
