#include "decls/data/records.h"
typedef unsigned __int64 U64;
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int);
class FUN_00240060 {
  public:
    FUN_00240060* FUN_0023fc40(const char*, int) throw();
    ~FUN_00240060() throw();
    char data[12];
};
class FUN_002605e0 {
  public:
    virtual void v();
    FUN_002605e0(FUN_00240060*, const U64&, int, int) throw();
};
class SeqEventExpressionType_250b20 : public FUN_002605e0 {
  public:
    SeqEventExpressionType_250b20();
    virtual void v();
};
SeqEventExpressionType_250b20::SeqEventExpressionType_250b20()
    : FUN_002605e0(FUN_00240060().FUN_0023fc40("$Exp", 0), FUN_002672f0("SeqEventExpression", 0, 0), (int)sizeof(AudioSeqEventExpression), (int)__alignof(AudioSeqEventExpression)) { HULK_SIZE32(AudioSeqEventExpression, 0x14); }