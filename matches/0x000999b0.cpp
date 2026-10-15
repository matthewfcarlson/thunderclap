class Elem {
  public:
    void A(float);
    void B(float);
};
class Obj {
    char pad[0xc4];
    Elem* p;

  public:
    void Fn(float a, float b);
};
void Obj::Fn(float a, float b) {
    ((Elem*)((char*)p + 0x250))->A(a);
    ((Elem*)((char*)p + 0x250))->B(b);
}