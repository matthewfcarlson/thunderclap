class Part {
  public:
    Part();
    ~Part();
};
class Next {
  public:
    Next();
    ~Next();
};
class Outer {
    char pad[16];
    Part part;
    Next next;

  public:
    Outer();
};
Outer::Outer() {}