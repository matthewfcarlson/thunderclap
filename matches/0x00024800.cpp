class Worker {
  public:
    int DoIt(int);
};

struct Container {
    char pad[0x44];
    Worker* worker;
};

class Owner {
  public:
    Container* mCont; // 0x00
    int f4;           // 0x04
    int f8;           // 0x08
    int count;        // 0x0c
    int arr[69];      // 0x10 .. 0x123
    int cmpVal;       // 0x124

    int func();
};

int Owner::func() {
    int sum = 0;
    int i = 0;
    if (count > 0) {
        int* p = arr;
        do {
            Worker* w = mCont->worker;
            int r = w->DoIt(*p);
            if (r != 0 && r != cmpVal)
                ++sum;
            ++i;
            ++p;
        } while (i < count);
    }
    return sum;
}
