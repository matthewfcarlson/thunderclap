extern char vtable_symbol[];
class FrameController { public: virtual void f(); char pad[12]; unsigned char value; FrameController* reset(); };
class Base { public: void initialize(); };
FrameController* FrameController::reset() { ((Base*)this)->initialize(); *(void**)this = vtable_symbol; value = 0; return this; }