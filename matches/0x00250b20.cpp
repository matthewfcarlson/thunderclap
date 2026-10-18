typedef unsigned __int64 U64;
extern "C" U64 __cdecl MakeId(const char*, int, int);
class Expr {
  public:
    Expr* Init(const char*, int) throw();
    ~Expr() throw();
    char data[12];
};
class Base {
  public:
    virtual void v();
    Base(Expr*, const U64&, int, int) throw();
};
class audioSeqEventExpressionType : public Base {
  public:
    audioSeqEventExpressionType();
    virtual void v();
};
audioSeqEventExpressionType::audioSeqEventExpressionType()
    : Base(Expr().Init("$Exp", 0), MakeId("SeqEventExpression", 0, 0), 20, 4) {}