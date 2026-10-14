class Sub {
  public:
    void Helper(int arg);
};

class Class {
  public:
    char pad[0x88];
    Sub* mPtr;
    void Wrapper(int arg);
};

void Class::Wrapper(int arg) {
    Sub* p = mPtr;
    if (p)
        p->Helper(arg);
}
