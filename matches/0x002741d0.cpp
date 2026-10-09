class FileIface {
  public:
    virtual void f0();
    virtual void f1();
};
struct CoreFile {
    char a[4];
    FileIface iface;
    char b[0xc];
    int state;
    char c[0x10c];
    int position;
};
class FileGetPositionRequest {
  public:
    char pad0[8];
    CoreFile* file;
    int* out;
    int vfunc_1();
};
int FileGetPositionRequest::vfunc_1() {
    *out = file->position;
    file->iface.f0();
    file->state = 0;
    file->iface.f1();
    return 1;
}