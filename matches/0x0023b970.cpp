class Helper_23b970 {
  public:
    unsigned int f1();
    unsigned int f2();
};
class StreamDataReader {
    char pad[8];
    Helper_23b970* h;

  public:
    bool vfunc_5();
};
bool StreamDataReader::vfunc_5() {
    unsigned int a = h->f1();
    unsigned int b = h->f2();
    return b <= a;
}