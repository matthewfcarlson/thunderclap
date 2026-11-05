#include "compat/ptr.h"
class DriveRequest_2757f0 {
  public:
    virtual void V();
    DriveRequest_2757f0(int);
};
class DriveFormatRequest : public DriveRequest_2757f0 {
  public:
    virtual void W();
    DriveFormatRequest(hulk_intptr);
};
extern void FinishInit();
DriveFormatRequest::DriveFormatRequest(hulk_intptr x) : DriveRequest_2757f0(x) {
    FinishInit();
}
