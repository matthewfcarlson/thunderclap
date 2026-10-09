class Arg {
  public:
    virtual void Init();
};
extern int table;
class StreamDataReader {
  public:
    int vf;
    int a;
    Arg* p;
    int q;
    StreamDataReader(Arg* x, int y);
};
StreamDataReader::StreamDataReader(Arg* x, int y) {
    a = 0;
    vf = (int)&table;
    q = y;
    p = x;
    p->Init();
}