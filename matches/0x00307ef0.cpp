class X {
  public:
    int n;
    int cap;
    char* buf;
    void grow(int);
    char* next();
};
char* X::next() {
    if (n >= cap)
        grow(cap * 2);
    ++n;
    return buf + n - 1;
}