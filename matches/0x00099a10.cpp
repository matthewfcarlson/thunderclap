class Obj_99a10 {
  public:
    char pad[0xc4];
    class Sub {
      public:
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void a3();
        virtual void a4();
        virtual void a5();
        virtual void a6();
        virtual void a7();
    }* m;
    void Fn();
};

void Obj_99a10::Fn() {
    m->a7();
}
