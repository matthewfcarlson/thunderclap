class CDisplayEffect {
  public:
    class DrawableText {
      public:
        virtual void f1();
        virtual void f2();
        void* a;
        void* b;
        DrawableText(void* x, void* y);
    };
};
CDisplayEffect::DrawableText::DrawableText(void* x, void* y) {
    a = x;
    b = y;
}