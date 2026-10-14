// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 16/16)
// FUN_000bb820 @ 0x000bb820
struct Provider_bb820 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual int get(); };
struct Text_bb820 { void FUN_000f8500(const char*, int, int); char storage[0x58]; };
struct Item_bb820 { char pad[0x18]; Text_bb820 text; int state; };
struct Owner_bb820 { char pad0[4]; Provider_bb820* provider; char pad1[0x984]; Item_bb820* mainItem; Item_bb820* secondItem; Item_bb820* thirdItem; void target(const char*, const char*, const char*); };
void Owner_bb820::target(const char* mainText, const char* secondText, const char* thirdText) {
 Text_bb820* text = &mainItem->text;
 int value = provider->get();
 text->FUN_000f8500(mainText, value, 1);
 if ((secondText && *secondText) || (thirdText && *thirdText)) mainItem->state = 1; else mainItem->state = 2;
 if (secondText && secondItem) { text = &secondItem->text; value = provider->get(); text->FUN_000f8500(secondText, value, 1); }
 if (thirdText && thirdItem) { text = &thirdItem->text; value = provider->get(); text->FUN_000f8500(thirdText, value, 1); }
}
