extern unsigned char DAT_004dd83b;
class Obj {
  public:
    void Fn(void* p);
    char pad[4];
    void* m;
};
void Obj::Fn(void* p) {
    if (m)
        DAT_004dd83b = (p == 0);
}