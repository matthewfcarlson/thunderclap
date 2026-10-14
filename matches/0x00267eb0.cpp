extern int gValue_267eb0;
void __cdecl Init();
class Object {
  public:
    virtual ~Object();
    int field;
    Object();
};
Object::Object() {
    field = gValue_267eb0;
    Init();
}