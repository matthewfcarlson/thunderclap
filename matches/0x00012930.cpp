class X {
  public:
    int* Target();
};
int* X::Target() {
    return (int*)((char*)this + 0x30);
}