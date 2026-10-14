namespace pure3d {
class CompositeDrawable;
}

class Obj_f2ba0 {
  public:
    virtual void AddRef();
};

namespace content {
class LoadInventory {
  public:
    template <class T> class DynamicCaster {
      public:
        virtual T* Cast(void* p);
    };
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual Obj_f2ba0* Find(const DynamicCaster<pure3d::CompositeDrawable>& c, __int64 uid);
};
} // namespace content

extern content::LoadInventory* gLoader;
extern "C" __int64 Hash(const char* s);

class FEContainer {
  public:
    virtual void v0();
    char pad[0x28 - 4];
    Obj_f2ba0* items[8];
    virtual void Add(const char* name);
};

void FEContainer::Add(const char* name) {
    int i = 0;
    Obj_f2ba0** p = items;
    do {
        if (*p == 0) {
            if (i < 8) {
                content::LoadInventory* ld = gLoader;
                __int64 uid = Hash(name);
                Obj_f2ba0* o = ld->Find(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>(), uid);
                items[i] = o;
                if (o)
                    o->AddRef();
            }
            return;
        }
        i++;
        p++;
    } while (i < 8);
}