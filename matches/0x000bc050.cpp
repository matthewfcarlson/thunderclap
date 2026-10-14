class Y_bc050 {
  public:
    void Fn(float);
};

class X_bc050 {
  public:
    char pad[4];
    Y_bc050* m;
    void Fn(float unused);
};

void X_bc050::Fn(float unused) {
    if (m)
        m->Fn(unused);
}
