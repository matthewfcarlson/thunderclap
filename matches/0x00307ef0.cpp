class X_307ef0 {
  public:
    int n;
    int cap;
    char* buf;
    void grow(int);
    char* next();
};
char* X_307ef0::next() {
    if (n >= cap)
        grow(cap * 2);
    ++n;
    return buf + n - 1;
}