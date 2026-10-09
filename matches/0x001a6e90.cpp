extern "C" int Compare(void*, int, const char*, const char*, int);
extern const char g1[];
extern const char g2[];
class Obj {
  public:
    void* Get();
    void* Run();
};
void* Obj::Run() {
    void* p = Get();
    while (p) {
        if (Compare(p, 0, g1, g2, 0))
            break;
        p = Get();
    }
    return p;
}