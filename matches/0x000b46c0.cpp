struct Object {
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
};
extern char DAT_0049dba4;
extern char DAT_0049f454;
extern void* __cdecl FUN_000fc260(const char*);
extern Object* __cdecl FUN_00344e74(void*, int, void*, void*, int);
void __cdecl FUN_000b46c0() {
    const char* names[] = {"comic_book_selector_1",
                           "comic_book_selector_2",
                           "comic_book_selector_3",
                           "comic_book_selector_4",
                           "comic_book_selector_5",
                           "comic_book_selector_6",
                           "character_selector_1",
                           "character_selector_2",
                           "character_selector_3",
                           "character_selector_4",
                           "enemy_selector_1",
                           "enemy_selector_2",
                           "environment_selector_1",
                           "environment_selector_2",
                           "environment_selector_3",
                           "environment_selector_4",
                           "character_render_selector_1",
                           "character_render_selector_2",
                           "character_render_selector_3",
                           "enemy_render_selector_1",
                           0};
    for (int i = 0; names[i]; ++i) {
        Object* obj = FUN_00344e74(FUN_000fc260(names[i]), 0, &DAT_0049dba4, &DAT_0049f454, 0);
        if (obj)
            obj->v21();
    }
}
