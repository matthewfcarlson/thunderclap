struct Sub {
    int x;
};
struct A {
    char pad[16];
    Sub sub;
    Sub* Get();
};
Sub* A::Get() {
    return &sub;
}