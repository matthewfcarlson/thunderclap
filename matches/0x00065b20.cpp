struct Manager {
    char pad[0x2c];
    void* item;
};
extern Manager* gManager;
extern const float gZero;
class Active {
  public:
    float check();
};
class Obj {
  public:
    void* ptr;
    Active* active;
    char pad[0x340];
    int a;
    int b;
    char p1[4];
    int c;
    char p2[4];
    int d;
    char p3[4];
    int e;
    void Run();
};
void Obj::Run() {
    if (active) {
        if (!ptr) {
            ptr = gManager->item;
            if (!ptr)
                return;
        }
        if (active->check() == gZero) {
            a = 0;
            b = 0;
            c = 0;
            d = 0;
            e = 0;
        }
    }
}