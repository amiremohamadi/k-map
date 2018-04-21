struct Pair {int i, j;};

class list
{
    private:
      Pair arr[16];
      int pointer = 0;

    public:
      list();
      ~list();
      void append(Pair);
      void clear();
      Pair get(int);
      void print();
};

class superList
{
    private:
      list arr[16];
      int pointer = 0;

    public:
      superList();
      void append(list);
      void clear();
      list get(int);
      void print();
};