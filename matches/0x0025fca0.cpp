extern "C" int strcmp(const char*, const char*);
class Text {
  public:
    const char* Get();
};
class Item {
  public:
    char pad[0x58];
    Text text;
};
extern "C" int FUN_0025fca0(void * a, void * b) {
    return strcmp(((Text *)a)->Get(), ((Item *)b)->text.Get());
}