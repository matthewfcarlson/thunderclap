struct A {
    char pad[0x18];
    A* Get();
};
A* A::Get() {
    return (A*)((char*)this + 0x18);
}
