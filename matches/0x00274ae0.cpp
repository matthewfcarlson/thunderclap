class DriveRequest { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int v6(); };
class DriveCancelRequest : public DriveRequest { public: int v6(); };
int DriveCancelRequest::v6() { return 0x14; }