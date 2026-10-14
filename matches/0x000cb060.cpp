class Sub_cb060 {
  public:
    void Helper(int arg);
};

class Class {
  public:
    char pad[0x88];
    Sub_cb060* mPtr;
    void Wrapper(int arg);
};

void Class::Wrapper(int arg) {
    Sub_cb060* p = mPtr;
    if (p)
        p->Helper(arg);
}
