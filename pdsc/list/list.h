class list
{
private:
  struct node
  {
    node *next;
    int val;
  };
  node * head;
  node *current;
public:
  list ();
  list (const list& l);
  list& operator=(const list& l);
  ~list ();
  void insert (int a);
  void goToHead ();
  int getCurrentData ();
  void advance ();
  bool moreData ();
};
