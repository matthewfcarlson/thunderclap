extern "C" char DAT_004166b8[];
extern "C" void* alloc(unsigned int);
class Condition {
  public:
    void init(int);
};
class Template {
  public:
    char pad[0x14];
};
void* target(Template* self) {
    Condition* p = (Condition*)alloc(0x14);
    if (p) {
        p->init(0);
        *(int*)p = ((int)DAT_004166b8);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return p;
    }
    return 0;
}