// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000bd050 @ 0x000bd050
class Screen_bd050 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int mode);
    virtual int v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int on);
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(int on);
};
class Layer_bd050 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16(int arg);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int arg);
};
class Viewport_bd050 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};
class Label_bd050 {
  public:
    void FUN_000f7d60(char* text, int a, float b, int c, int d, int e);
};
class TextManager_bd050 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Label_bd050* v44();
};
struct Canvas {
    Layer_bd050* layer;
    void FUN_00293d40(float x, float y, float z);
    void FUN_00293da0(float x, float y, float z);
};
class MenuScreen_bd050 {
  public:
    void FUN_000bc900(char* out, int a, const char* name, int b);
    void FUN_000bd050();
};
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;
extern Screen_bd050* DAT_0052c2a8;
extern Canvas* DAT_0052c2ac;
extern Viewport_bd050* DAT_0052c2a4;
TextManager_bd050* FUN_000fc3d0();

void MenuScreen_bd050::FUN_000bd050() {
    volatile unsigned int cookie = DAT_004d9968;
    char text[0x200];
    int saved = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(2);
    DAT_0052c2a8->v54(0);
    DAT_0052c2a8->v58(0);
    DAT_0052c2ac->layer->v21(0);
    float width = (float)DAT_0052c2a4->v7();
    float height = (float)DAT_0052c2a4->v6() - 50.0f;
    FUN_000bc900(text, 0, "TBS_MENU_ITEM_BUTTON_BACK", 1);
    DAT_0052c2ac->FUN_00293d40(width * 0.5f, height, 2.0f);
    DAT_0052c2ac->FUN_00293da0(1.0f, -1.0f, 1.0f);
    FUN_000fc3d0()->v44()->FUN_000f7d60(text, 0, 1.4f, 1, 2, 0);
    DAT_0052c2a8->v54(1);
    DAT_0052c2a8->v58(1);
    DAT_0052c2ac->layer->v16(0);
    DAT_0052c2a8->v24(saved);
    __security_check_cookie(cookie);
}
