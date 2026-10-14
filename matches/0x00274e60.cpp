extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
typedef unsigned int u32_274e60;
struct Inner_274e60 {
    virtual void a();
    virtual void b();
};
struct File {
    virtual void a();
    char pad[0x14];
    int count;
};
struct Request {
    u32_274e60 vf;
    u32_274e60 field;
    File* file;
};
void init();
struct Target_274e60 : Request {
    Request* run(u32_274e60 arg);
};
Request* Target_274e60::run(u32_274e60 arg) {
    vf = ((int)DAT_0042b914);
    field = 0;
    init();
    vf = ((int)DAT_0042b99c);
    file = (File*)arg;
    init();
    ((Inner_274e60*)((char*)file + 4))->a();
    ++file->count;
    ((Inner_274e60*)((char*)file + 4))->b();
    file->a();
    return this;
}