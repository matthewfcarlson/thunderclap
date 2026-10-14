class X_2393c0 {
  public:
    char pad[0x14];
    int* m;
    int** Get();
};

int** X_2393c0::Get() {
    return &m;
}
