// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00275600 @ 0x00275600
namespace core {
struct Lock_275600 { virtual void enter(); virtual void leave(); };
struct Drive { virtual void acquire(); Lock_275600 lock; char pad[12]; unsigned count; };
struct Request {
 virtual void dummy();
 unsigned state;
 void FUN_002705f0();
 Request() : state(0) { FUN_002705f0(); }
};
struct DriveRequest : Request {
 virtual void dummy();
 Drive* drive;
 DriveRequest(Drive* p);
};
DriveRequest::DriveRequest(Drive* p) : Request() {
 drive=p;
 FUN_002705f0();
 drive->lock.enter();
 ++drive->count;
 drive->lock.leave();
 drive->acquire();
}
}
