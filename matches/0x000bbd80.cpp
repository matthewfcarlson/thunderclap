unsigned char gFlag;
class Obj {
  public:
    char pad[4];
    void* ptr;
    void Set(void* p);
};
void Obj::Set(void* p) {
    if (ptr)
        gFlag = (p == 0);
}