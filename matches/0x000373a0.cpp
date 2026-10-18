extern "C" int strcmp(const char*, const char*);
class Obj {
  public:
    char pad[0x20b8];
    char m[5];
    char Fn(int);
};
char Obj::Fn(int x) {
    return strcmp((const char*)m, "hulk") == 0;
}
