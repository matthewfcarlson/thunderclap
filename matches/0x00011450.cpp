struct A {
    A* Get();
};

A* A::Get() {
    return this;
}
