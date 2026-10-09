typedef unsigned int size_t; typedef unsigned int u32;
void* __cdecl alloc(size_t);
namespace pure3d {
class SpriteObject;
class Builder { public: void init(SpriteObject*); };
class SpriteObject {
public:
 virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual SpriteObject* a4();
};
SpriteObject* SpriteObject::a4() {
 SpriteObject* p=(SpriteObject*)alloc(0x58);
 if(p) { ((Builder*)p)->init(this); *(u32*)p=0x42e914; return p; }
 return 0;
}
}