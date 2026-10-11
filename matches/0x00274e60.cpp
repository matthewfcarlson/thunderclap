extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
typedef unsigned int u32;
struct Inner {
    virtual void a();
    virtual void b();
};
struct File {
    virtual void a();
    char pad[0x14];
    int count;
};
struct Request {
    u32 vf;
    u32 field;
    File* file;
};
void init();
struct Target : Request {
    Request* run(u32 arg);
};
Request* Target::run(u32 arg) {
    vf = ((int)DAT_0042b914);
    field = 0;
    init();
    vf = ((int)DAT_0042b99c);
    file = (File*)arg;
    init();
    ((Inner*)((char*)file + 4))->a();
    ++file->count;
    ((Inner*)((char*)file + 4))->b();
    file->a();
    return this;
}