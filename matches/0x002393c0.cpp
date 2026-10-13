class X {
  public:
    char pad[0x14];
    int* m;
    int** Get();
};

int** X::Get() {
    return &m;
}
