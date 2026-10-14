struct Sub_24150 {
    void Helper();
};
struct Owner_24150 {
    char pad[0x40];
    void Func();
};
void Owner_24150::Func() {
    Sub_24150* p = (Sub_24150*)((char*)this + 0x48);
    p->Helper();
    p = (Sub_24150*)((char*)this + 0x40);
    p->Helper();
}