namespace Rigid2D {
  class Exception {
    protected:
      const long line_;
      const char * function_;
      const char * file_;
      const char * description_;
    public:
      Exception ( long line, const char * function, const char * file, 
          const char * description = "" ) : line_(line),
                                            function_(function),
                                            file_(file),
                                            description_(description) { }
      long getLine ( ) { return line_; }
      const char * getFunc () { return function_; }
      const char * getFile () { return file_; }
      const char * getDesc () { return description_; }
  };
}
