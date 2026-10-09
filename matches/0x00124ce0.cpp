class Helper { public: Helper *Get(); Helper *Next(); int Check(); void Act(); };
class ClearProjectileDistanceAction { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual bool vfunc_5(int,int); char pad[0x18]; char *mData; Helper *mHelper; };
bool ClearProjectileDistanceAction::vfunc_5(int a,int b) {
 if (a != 0) goto done;
 { Helper *x=mHelper->Get(); x=x->Next(); if(mData[0x14] && x->Check()) x->Act(); }
done:
 return true;
}