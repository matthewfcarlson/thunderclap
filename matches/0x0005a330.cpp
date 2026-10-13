struct S {
    char pad[0xc];
    int value;
};
struct O {
    char pad[0xc];
    S* Get();
};
S* O::Get() {
    return (S*)((char*)this + 0xc);
}
