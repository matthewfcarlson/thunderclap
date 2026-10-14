class Y {
  public:
    void Fn(float);
};

class X {
  public:
    char pad[4];
    Y* m;
    void Fn(float unused);
};

void X::Fn(float unused) {
    if (m)
        m->Fn(unused);
}
