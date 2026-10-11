extern "C" char DAT_0048d5bc[];
extern "C" char DAT_004a15cc[];
class Owner {
  public:
    void* Get();
    void* Find();
};
extern int Check(void*, int, void*, void*, int);
void* Owner::Find() {
    void* p = Get();
    while (p != 0 && Check(p, 0, (void*)((int)DAT_0048d5bc), (void*)((int)DAT_004a15cc), 0) == 0) {
        p = Get();
    }
    return p;
}