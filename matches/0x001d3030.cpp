extern const char actors[];
extern const char command[];
extern "C" void Apply(void*, int);
extern "C" void Reset(void*, int);
extern "C" int Finish(void*, int);
extern "C" void Cleanup(void*, int);

class Obj_1d3030 {
  public:
    char pad[8];
    void* ptr;
    char Check(const char*, int, int);
    int Run(const char*, int);
};

int Obj_1d3030::Run(const char* a, int b) {
    int result = 0;
    if (Check(actors, 1, 1)) {
        if (Check(a, 0, 1)) {
            if (Check(command, 0, 1)) {
                Apply(ptr, b);
                Reset(ptr, -2);
                result = Finish(ptr, -1);
            }
        }
    }
    Cleanup(ptr, 0);
    return result;
}
