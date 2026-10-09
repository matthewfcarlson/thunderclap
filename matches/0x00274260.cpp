class FileOps {
  public:
    virtual void First();
    virtual void Second();
};
class File {
  public:
    char pad0[4];
    FileOps ops;
    char pad14[0x14 - 8];
    int state;
    char pad1c[0x128 - 0x18];
    int size;
};
class FileGetSizeRequest {
  public:
    char pad0[8];
    File* file;
    int* out;
    int vfunc_1();
};
int FileGetSizeRequest::vfunc_1() {
    *out = file->size;
    file->ops.First();
    file->state = 0;
    file->ops.Second();
    return 1;
}