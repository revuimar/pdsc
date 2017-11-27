class Stack
{
	public:
		void push(int element);
		int pop();
		void clear();
		bool isEmpty();
		Stack(unsigned int sizeIncrement);
		Stack();
		~Stack();
	private:
		int top;
		int* data;
		int size;
};
