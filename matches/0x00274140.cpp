struct Sub {
    virtual void a();
    virtual void b();
};
struct File {
    char pad0[4];
    Sub sub;
    char pad1[0xc];
    int state;
    char pad2[0x124 - 0x18];
    int position;
};
struct FileSetPositionRequest {
    char pad[8];
    File* file;
    int position;
    int vfunc_1();
};
int FileSetPositionRequest::vfunc_1() {
    file->position = position;
    file->sub.a();
    file->state = 0;
    file->sub.b();
    return 1;
}
