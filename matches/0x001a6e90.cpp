extern "C" int Compare(void*, int, const char*, const char*, int);
extern const char g1_1a6e90[];
extern const char g2_1a6e90[];
class Obj_1a6e90 {
  public:
    void* Get();
    void* Run();
};
void* Obj_1a6e90::Run() {
    void* p = Get();
    while (p) {
        if (Compare(p, 0, g1_1a6e90, g2_1a6e90, 0))
            break;
        p = Get();
    }
    return p;
}