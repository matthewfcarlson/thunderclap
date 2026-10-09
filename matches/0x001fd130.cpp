class Elem {
  public:
    char pad[0x458];
    int mFlag;
    char pad2[0xc70 - 0x45c];
    bool Check(void* p);
    void Do(void* p);
};

class Container {
  public:
    char pad[0x234];
    int mArray;
    void Target(void* p2, void* p3);
};

void Container::Target(void* p2, void* p3) {
    for (int i = 0; i < 0x6380; i += 0xc70) {
        Elem* e = (Elem*)(mArray + i);
        if (e->mFlag != 0) {
            if (((Elem*)(mArray + i))->Check(p3)) {
                ((Elem*)(mArray + i))->Do(p2);
            }
        }
    }
}
