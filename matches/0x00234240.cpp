class Enumerator { public: virtual int Get(int index); int Count(); };
int Enumerator::Count() {
    int i = 0;
    while (Get(i) != 0) ++i;
    return i;
}