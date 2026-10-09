struct B {
    char pad[0x44];
    struct Lookuper* lk;
};
struct Lookuper {
    int Lookup(int key);
};
struct Node {
    char pad[0x20a8];
    int a;
    int b;
};

class Target {
  public:
    B* mB;
    int pad1[2];
    int mCount;
    int mArr[1];
    bool Process();
};

bool Target::Process() {
    int n = mCount;
    int i = 0;
    if (n > 0) {
        int* p = mArr;
        do {
            Lookuper* l = mB->lk;
            Node* node = (Node*)l->Lookup(*p);
            if (node != 0) {
                node->a = node->b;
            }
            n = mCount;
            ++i;
            ++p;
        } while (i < n);
    }
    return true;
}
