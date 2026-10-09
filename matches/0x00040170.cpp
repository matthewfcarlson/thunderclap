class X { public: bool f(int); bool target(); };
bool X::target() { bool bad=false; for(int i=0;i<8;i++) if(!f(i)) bad=true; return !bad; }