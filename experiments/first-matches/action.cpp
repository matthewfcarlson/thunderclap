// Matching experiment (names/layouts are guesses). Verify with:
//   build/venv/bin/python tools/compare.py <this file> <symbol> <address>

class CAction {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual bool Dispatch(int type, int arg);
    virtual void v6();
    virtual bool OnType1(int arg);
    virtual bool OnType0(int arg);
};

// FUNCTION: 0x00013950 (CAction::vfunc_5)
bool CAction::Dispatch(int type, int arg) {
    bool result = false;
    switch (type) {
    case 0: result = OnType1(arg); break;
    case 1: result = OnType0(arg); break;
    }
    return result;
}

struct Info { char pad[0x58]; float value; };
class Source { public: virtual void a(); virtual void b(); virtual void c(); virtual Info* GetInfo(); };

extern const float kDefaultValue;

class CHitAnimationAction {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual float GetValue();
    char pad[0x18];
    Source* mSource;
};

// FUNCTION: 0x00014900 (CHitAnimationAction::vfunc_9)
float CHitAnimationAction::GetValue() {
    Info* info = mSource->GetInfo();
    if (info == 0) return kDefaultValue;
    return info->value;
}
