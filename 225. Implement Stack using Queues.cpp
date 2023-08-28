#include <iostream>
#include <queue>

using namespace std;

class MyStack
{
public:
    queue<int> q1, q2;
    int size;

    MyStack()
    {
        size = 0;
    }

    void push(int x)
    {

        size++;
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    int pop()
    {
        size--;
        int x = q1.front();
        q1.pop();

        return x;
    }

    int top()
    {

        return q1.front();
    }

    bool empty()
    {

        if (size == 0)
            return true;

        return false;
    }
};

int main()
{

    MyStack st;

    st.push(1);
    st.push(2);
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.empty() << endl;

    return 0;
}