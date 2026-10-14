class A_16e740 {
  public:
    char pad[0x18];
    int m18;
    int* Get();
};

int* A_16e740::Get() {
    return &m18;
}
