struct Data_16f2e0 {
    int a;
    int b;
    int c;
};

class Ctx_16f2e0 {
  public:
    char pad[0x2c];
    int m2c;
    int m30;
    int m34;
    char Set(Data_16f2e0* d);
};

char Ctx_16f2e0::Set(Data_16f2e0* d) {
    m2c = d->a;
    m30 = d->b;
    m34 = d->c;
    return 1;
}
