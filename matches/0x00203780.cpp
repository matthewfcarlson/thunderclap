class Vec_203780 {
  public:
    char pad[0xa4c];
    int mCount;
    void* mItems[1];
    void Add(void* item);
};

void Vec_203780::Add(void* item) {
    mItems[mCount] = item;
    mCount++;
}
