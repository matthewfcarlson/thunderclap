class Obj_1e4760 {
  public:
    Obj_1e4760() throw();
    ~Obj_1e4760() throw();
    void Setup(int);
};
class Self_1e4760 {
  public:
    void Draw(int, int, int, int, int, int, int);
    void Fn(int, Obj_1e4760*, int, int, int, int, int);
};
void Self_1e4760::Draw(int a, int b, int c, int d, int e, int f, int g) {
    static Obj_1e4760 s;
    s.Setup(b);
    Fn(a, &s, c, d, e, f, g);
}