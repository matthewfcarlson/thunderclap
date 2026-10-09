class Obj { public: virtual void V0(); virtual void V1(); };
class Inner { public: void Init(); void SetName(const char *); };
class Base { public: Base(); virtual void A0(); };
class Action : public Base {
public:
 Action(int arg, Obj *obj);
 virtual void A0();
 char pad04[0x18]; int field1c; Obj *field20; char pad24[4]; Inner inner;
};
Action::Action(int arg, Obj *obj) {
 field1c = 0; field20 = 0;
 inner.Init(); field1c = arg;
 if (obj) obj->V0();
 if (field20) field20->V1();
 field20 = obj;
 inner.SetName((const char*)0x417da4);
}
