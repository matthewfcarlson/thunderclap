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
    v = 0x42ba00;
    field = b;
    flag = c;
    post();
    return this;
}