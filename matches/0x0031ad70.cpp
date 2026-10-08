namespace pure3d {
class pddiDisplay { public: virtual void v0(); virtual void v1(); virtual void v2(); };
class pddiObject { };
class d3dDisplay : public pddiDisplay, public pddiObject {
public:
 virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
 virtual unsigned int vfunc_11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 char pad[0x470 - 4];
};
unsigned int d3dDisplay::vfunc_11() { return *(unsigned int*)((char*)this + 0x470); }
}