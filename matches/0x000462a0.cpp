class Base {
  public:
    int vptr;
    Base();
    int data;
};
Base::Base() {
    vptr = 0x3f6338;
}
