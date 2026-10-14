class A_1aadb0 {
  public:
    char pad[0x10];
    int* Get();
};
int* A_1aadb0::Get() {
    return (int*)((char*)this + 0x10);
}