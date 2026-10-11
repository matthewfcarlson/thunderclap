extern "C" char DAT_0042efc0[];
class VertexList {
  public:
    int vptr;
    int a;
    int b;
    int c;
    int d;
    int e[12];
    int pad[6];
    int q;
    int r;
    int s;
    void init(int, int, int);
    VertexList(int, int, int);
};
VertexList::VertexList(int p2, int p3, int p4) {
    b = p2;
    a = 0;
    vptr = ((int)DAT_0042efc0);
    c = p3;
    d = p4;
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
    e[3] = 0;
    e[4] = 0;
    e[5] = 0;
    e[6] = 0;
    e[7] = 0;
    e[8] = 0;
    pad[3] = 0;
    pad[4] = 0;
    pad[5] = 0;
    init(p2, p3, p4);
}