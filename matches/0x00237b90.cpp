class O {
  public:
    char pad[0x1c];
    int m;
    int* Get();
};

int* O::Get() {
    return &m;
}
