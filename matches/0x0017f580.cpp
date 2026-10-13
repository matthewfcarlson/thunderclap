struct T {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* member();
    char pad[24];
};
char* T::member() {
    return (char*)this + 0x18;
}