struct Point {
    int x, y, z;
};
class Obj {
  public:
    char pad[0xe0];
    int a, b, c;
    bool Set(Point* p);
};
bool Obj::Set(Point* p) {
    a = p->x;
    b = p->y;
    c = p->z;
    return true;
}
