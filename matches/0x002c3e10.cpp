class Base { public: virtual void f(); Base(); };
class PointLight : public Base { public: char pad[0x50]; int a; float b; int c,d,e; PointLight(); };
PointLight::PointLight() : Base() { c=0; d=0; e=0; b=1.0f; a=1; }