extern int gValue;
void __cdecl Init();
class Object { public: virtual ~Object(); int field; Object(); };
Object::Object() { field = gValue; Init(); }