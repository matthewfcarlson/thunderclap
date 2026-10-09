class C {
  public:
    char pad[0xbc];
    int value;
    void first();
    void second(int);
    void third();
    void target(int);
};
void C::target(int arg) {
    first();
    ((C*)((char*)this + 0x14))->second(arg);
    value = 2;
    third();
}