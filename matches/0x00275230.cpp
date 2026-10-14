extern "C" char DAT_0042baa0[];
typedef unsigned int u32_275230;
class Base_275230 {
  public:
    int pad[3];
    Base_275230(u32_275230);
};
extern void Finish();
class FileReadRequest : public Base_275230 {
  public:
    int a, b, c;
    FileReadRequest(u32_275230, u32_275230, u32_275230, u32_275230);
};
FileReadRequest::FileReadRequest(u32_275230 x, u32_275230 y, u32_275230 z, u32_275230 w) : Base_275230(x) {
    *(u32_275230*)this = ((int)DAT_0042baa0);
    a = y;
    b = z;
    c = w;
    Finish();
}