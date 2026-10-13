class Foo {
  public:
    char pad[0x14];
    int mVal;
    int* Get();
};

int* Foo::Get() {
    return &mVal;
}
