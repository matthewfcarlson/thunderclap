class A_129e0 {
  public:
    char pad[0x10];
    int* Get();
};
int* A_129e0::Get() {
    return (int*)((char*)this + 0x10);
}
