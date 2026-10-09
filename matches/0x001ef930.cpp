class Helper { public: void A(); void B(int); char pad[8]; float x; int y; };
class CSoundTriggerExecutionState { public: virtual void V(); int a,b,c,d; char e; char pad[3]; Helper m; CSoundTriggerExecutionState(); };
CSoundTriggerExecutionState::CSoundTriggerExecutionState() { a=1; m.A(); b=0; c=0; d=0; e=0; m.x=100.0f; m.y=0; m.B(0); }