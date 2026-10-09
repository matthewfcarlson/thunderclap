class Base { public: virtual void v(); Base(int); char pad[0x7c]; int a,b,c; char p[0x44]; float d; int e,f; };
class Shader : public Base { public: virtual void v(); Shader(int); };
Shader::Shader(int x) : Base(x) { c=0; b=0; a=0; d=1.0f; e=4; f=0x20; }