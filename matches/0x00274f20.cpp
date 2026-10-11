extern "C" char DAT_0042ba00[];
class FileOpenRequest {
  public:
    int v;
    char pad[8];
    int field;
    unsigned char flag;
    void init(int);
    FileOpenRequest* target(int, int, unsigned char);
};
extern void post();
FileOpenRequest* FileOpenRequest::target(int a, int b, unsigned char c) {
    init(a);
    v = ((int)DAT_0042ba00);
    field = b;
    flag = c;
    post();
    return this;
}