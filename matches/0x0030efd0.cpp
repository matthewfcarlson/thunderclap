// Same code shape as 0x0030efa0 (propagated; names are from that function)
class C_30efd0 {
  public:
    char pad[0xbc];
    int value;
    void first();
    void second(int);
    void third();
    void target(int);
};
void C_30efd0::target(int arg) {
    first();
    ((C_30efd0*)((char*)this + 0x14))->second(arg);
    value = 2;
    third();
}