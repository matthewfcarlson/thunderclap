struct S_5a330 {
    char pad[0xc];
    int value;
};
struct O_5a330 {
    char pad[0xc];
    S_5a330* Get();
};
S_5a330* O_5a330::Get() {
    return (S_5a330*)((char*)this + 0xc);
}
