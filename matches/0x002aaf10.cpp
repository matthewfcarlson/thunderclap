extern int vtLoader;
extern int vtRef;
class Ref {
  public:
    virtual void V0();
    virtual void Release();
};
class Loader {
  public:
    unsigned char pad[0x14];
    unsigned int count;
    Ref* items[8];
    void Destroy();
};
void Loader::Destroy() {
    unsigned int i = 0;
    *(int*)this = (int)&vtLoader;
    while (i < count) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
        ++i;
    }
    if (items[8]) {
        items[8]->Release();
        items[8] = 0;
    }
    *(int*)this = (int)&vtRef;
}