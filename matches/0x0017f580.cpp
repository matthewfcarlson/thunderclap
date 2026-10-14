struct T_17f580 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* member();
    char pad[24];
};
char* T_17f580::member() {
    return (char*)this + 0x18;
}