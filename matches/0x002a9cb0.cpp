class Base { public: virtual void f(); char pad[0x3c]; Base(); };
class ExpressionAnimationController : public Base { public: int a,b,c,d; virtual void g(); ExpressionAnimationController(); };
ExpressionAnimationController::ExpressionAnimationController() { a=0; b=0; c=0; d=0; }
