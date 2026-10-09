struct E {
    int a, b;
    E() : a(0), b(0) {}
};
class Data {
  public:
    E a[64];
    E b[64];
    E c[64];
    E d[64];
    Data();
};
Data::Data() {}