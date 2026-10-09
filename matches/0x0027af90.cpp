class Pair {
  public:
    int a;
    int b;
    bool operator==(const Pair& other);
};
bool Pair::operator==(const Pair& other) {
    return a == other.a && b == other.b;
}