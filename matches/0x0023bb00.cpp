#include "compat/ptr.h"
class Arg_23bb00 {
  public:
    virtual void Init();
};
extern int table_23bb00;
class StreamDataReader {
  public:
    hulk_intptr vf;
    int a;
    Arg_23bb00* p;
    int q;
    StreamDataReader(Arg_23bb00* x, int y);
};
StreamDataReader::StreamDataReader(Arg_23bb00* x, int y) {
    a = 0;
    vf = (hulk_intptr)&table_23bb00;
    q = y;
    p = x;
    p->Init();
}