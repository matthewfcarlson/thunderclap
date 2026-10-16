extern unsigned char gFlag;
class Obj {
  public:
    void Fn(void* p);
    char pad[4];
    void* m;
};
void Obj::Fn(void* p) {
    if (m)
        gFlag = (p == 0);
}