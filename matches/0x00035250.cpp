struct Blk_35250 {
    unsigned int d[16];
};
class Source_35250 {
  public:
    void* Get();
};
class Image {
  public:
    Blk_35250* Data();
};
class C_35250 {
  public:
    char pad[0x10];
    Source_35250* member;
    int Run(unsigned int* p);
    int Finish(Blk_35250* b);
};
int C_35250::Run(unsigned int* p) {
    Blk_35250 local;
    void* x = member->Get();
    if (x) {
        Image* q = (Image*)((char*)x + 0x10);
        Blk_35250* src = q->Data();
        local = *src;
    }
    local.d[12] = p[0];
    local.d[13] = p[1];
    local.d[14] = p[2];
    return Finish(&local);
}
