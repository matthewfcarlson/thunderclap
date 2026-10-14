class Pair_27af90 {
  public:
    int a;
    int b;
    bool operator==(const Pair_27af90& other);
};
bool Pair_27af90::operator==(const Pair_27af90& other) {
    return a == other.a && b == other.b;
}