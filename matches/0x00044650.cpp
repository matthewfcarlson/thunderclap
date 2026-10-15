struct Vec {
    float x, y, z;
    Vec() : x(0.0f), y(0.0f), z(0.0f) {}
};
class Obj {
    char pad[0xa4];
    Vec elems[1];

  public:
    Vec* Get(int n);
};
Vec* Obj::Get(int n) {
    static Vec zero;
    if (n == 0)
        return &zero;
    return &elems[n];
}