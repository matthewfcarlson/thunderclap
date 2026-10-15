struct Blob {
    unsigned int x[174];
};
class Obj {
  public:
    char pad[8];
    unsigned int value;
    void Next(int, Blob, unsigned int);
    void Fn(int a, Blob b);
};
void Obj::Fn(int a, Blob b) {
    Next(a, b, value);
}