class Helper {
  public:
    unsigned int f1();
    unsigned int f2();
};
class StreamDataReader {
    char pad[8];
    Helper* h;

  public:
    bool vfunc_5();
};
bool StreamDataReader::vfunc_5() {
    unsigned int a = h->f1();
    unsigned int b = h->f2();
    return b <= a;
}