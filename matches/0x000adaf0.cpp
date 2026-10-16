extern "C" void* memset(void*, int, unsigned int);
class Obj {
  public:
    char pad[0xa0];
    int a, b, c;
    void Clear();
};
void Obj::Clear() {
    memset(&a, 0, 12);
}