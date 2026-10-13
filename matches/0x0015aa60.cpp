class X {
  public:
    char pad[0x78];
    int* Get();
};
int* X::Get() {
    return (int*)((char*)this + 0x78);
}