class CScriptToken {
  public:
    virtual ~CScriptToken();
    int a;
    int b;
    int c;
    CScriptToken(const CScriptToken&);
};
CScriptToken::CScriptToken(const CScriptToken& other) {
    a = other.a;
    b = other.b;
    c = other.c;
}