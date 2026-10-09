extern const char expr[];
class Base {
  public:
    Base();
};
class Text {
  public:
    void Set(const char*, int);
};
class SeqEventExpression : public Base {
  public:
    int vptr;
    char pad[4];
    Text text;
    SeqEventExpression();
};
SeqEventExpression::SeqEventExpression() {
    vptr = 0x429c8c;
    text.Set(expr, 2);
}