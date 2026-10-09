class Obj {
  public:
    Obj() throw();
    ~Obj() throw();
    void Setup(int);
};
class Self {
  public:
    void Draw(int, int, int, int, int, int, int);
    void Fn(int, Obj*, int, int, int, int, int);
};
void Self::Draw(int a, int b, int c, int d, int e, int f, int g) {
    static Obj s;
    s.Setup(b);
    Fn(a, &s, c, d, e, f, g);
}