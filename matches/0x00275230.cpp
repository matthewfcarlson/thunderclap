extern "C" char DAT_0042baa0[];
typedef unsigned int u32;
class Base {
  public:
    int pad[3];
    Base(u32);
};
extern void Finish();
class FileReadRequest : public Base {
  public:
    int a, b, c;
    FileReadRequest(u32, u32, u32, u32);
};
FileReadRequest::FileReadRequest(u32 x, u32 y, u32 z, u32 w) : Base(x) {
    *(u32*)this = ((int)DAT_0042baa0);
    a = y;
    b = z;
    c = w;
    Finish();
}