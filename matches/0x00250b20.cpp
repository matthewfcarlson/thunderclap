typedef unsigned __int64 U64;
extern "C" U64 __cdecl MakeId(const char*, int, int);
class Expr {
  public:
    Expr* Init(const char*, int) throw();
    ~Expr() throw();
    char data[12];
};
class SeqEventType_250b20 {
  public:
    virtual void v();
    SeqEventType_250b20(Expr*, const U64&, int, int) throw();
};
class SeqEventExpressionType_250b20 : public SeqEventType_250b20 {
  public:
    SeqEventExpressionType_250b20();
    virtual void v();
};
SeqEventExpressionType_250b20::SeqEventExpressionType_250b20()
    : SeqEventType_250b20(Expr().Init("$Exp", 0), MakeId("SeqEventExpression", 0, 0), 20, 4) {}