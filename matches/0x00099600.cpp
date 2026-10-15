struct Sub {
    void A(int);
    void B(int);
};
struct Obj {
    char pad[0xc4];
    Sub* p;
    void Fn(int a, int b);
};
void Obj::Fn(int a, int b) {
    Sub* q = (Sub*)((char*)p + 0x170);
    q->A(a);
    q = (Sub*)((char*)p + 0x170);
    q->B(b);
}