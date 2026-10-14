struct Data {
    int a;
    int b;
    int c;
};

class Ctx {
  public:
    char pad[0x2c];
    int m2c;
    int m30;
    int m34;
    char Set(Data* d);
};

char Ctx::Set(Data* d) {
    m2c = d->a;
    m30 = d->b;
    m34 = d->c;
    return 1;
}
