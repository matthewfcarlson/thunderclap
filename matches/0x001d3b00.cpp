struct Blob {
    unsigned int x[174];
};
class Obj {
  public:
    char pad[8];
    unsigned int value;
    int Next(int, Blob, unsigned int);
    int Fn(int a, Blob b);
};
int Obj::Fn(int a, Blob b) {
    return Next(a, b, value);
}