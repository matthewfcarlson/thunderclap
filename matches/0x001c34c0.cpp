class Obj {
  public:
    Obj();
    int a[7];
    char pad[0x40];
    float f, g, h, j;
    char pad2;
    char b, c, d;
    int x, y, z;
};
Obj::Obj() {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    a[6] = 0;
    f = 1.3f;
    g = 1.0f;
    h = 1.0f;
    j = 1000.0f;
    b = 0;
    c = 0;
    d = 0;
    x = 0;
    y = 0;
    z = 0;
}