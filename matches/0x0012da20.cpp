class Action { public: virtual void f0(); virtual void f1(); virtual void f2(); };
class PostEvent_StringAction : public Action { public: virtual unsigned char f3(int a, int b); };
unsigned char PostEvent_StringAction::f3(int a, int b) { return 1; }