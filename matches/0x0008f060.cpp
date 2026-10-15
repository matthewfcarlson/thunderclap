extern "C" unsigned int strlen(const char*);
class Hash {
  public:
    int Calc(const char* s);
};
int Hash::Calc(const char* s) {
    int n = strlen(s);
    int sum = n;
    int product = 1;
    for (int i = 0; i < n; ++i) {
        int v = (signed char)s[i];
        sum += v;
        product *= v;
    }
    return sum + product;
}