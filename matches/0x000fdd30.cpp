int __cdecl GetVal(int elem);

class Other {
  public:
    int Check(int v);
};

class Container {
  public:
    int FindSomething(int arg);
    char pad[8];
    int mCount;
    int mArray[1];
};

int Container::FindSomething(int arg) {
    Other* o = (Other*)arg;
    int e;
    int i = 0;
    if (mCount > 0) {
        int* p = mArray;
        do {
            e = *p;
            if (o->Check(GetVal(e))) {
                return e;
            }
            ++i;
            ++p;
        } while (i < mCount);
    }
    return 0;
}
