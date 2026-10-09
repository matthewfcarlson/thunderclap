extern const float Zero;
extern const float Limit;
class Inner { public: void Set(float); };
struct Holder { Inner* obj; };
class C { public: Holder* holder; char pad[0x10]; float value; void F(float x); };
void C::F(float x) {
    if (!(x < Zero) && !(x > Limit)) {
        holder->obj->Set(x);
        value = x;
    }
}
