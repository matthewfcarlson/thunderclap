extern "C" void _ReadWriteBarrier();
extern char VT[];
class CollisionSphere {
  public:
    CollisionSphere();
    int vptr;
    int a;
    int b;
    int c;
    int d;
    int e;
    char flag1;
    char flag2;
    char pad[2];
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};

CollisionSphere::CollisionSphere() {
    a = 0;
    d = 0;
    e = 0;
    flag1 = 1;
    flag2 = 0;
    _ReadWriteBarrier();
    b = -1;
    c = b;
    f = 0;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
    k = 0;
    l = 0x3f800000;
    vptr = (int)VT;
}
