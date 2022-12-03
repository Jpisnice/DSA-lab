/*
    text editor with the use of stack
*/

#include <iostream>
#include <string>

using namespace std;

class Stack
{
    private:
        struct Node
        {
            char data;
            Node *next;
        };
        Node *top;
    public:
        Stack()
        {
            top = NULL;
        }
        void push(char);
        char pop();
        char peek();
        bool isEmpty();
        void display();
};

void Stack::push(char ch)
{
    Node *newNode = new Node;
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

char Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        char ch = temp->data;
        delete temp;
        return ch;
    }
}

char Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else
    {
        return top->data;
    }
}

bool Stack::isEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}


void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

class textEditor
{
    private:
        Stack s1, s2;
        string text;
    public:
        textEditor()
        {
            text = "";
        }
        void insert(char);
        void insertString(string);
        void del();
        void left();
        void right();
        void display();
};

void textEditor::insert(char ch)
{
    s1.push(ch);
}

void textEditor::insertString(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        s1.push(str[i]);
    }
}

void textEditor::del()
{
    s1.pop();
}

void textEditor::left()
{
    s2.push(s1.pop());
}

void textEditor::right()
{
    s1.push(s2.pop());
}

void textEditor::display()
{
    while (!s1.isEmpty())
    {
        s2.push(s1.pop());
    }
    while (!s2.isEmpty())
    {
        cout << s2.peek();
        s1.push(s2.pop());
    }
    cout << endl;
}

/*Menu driven driver code*/

int main()
{
    textEditor t;
    int choice;
    char ch;
    string str;
    do
    {
        cout << "1. Insert" << endl;
        cout << "2. Insert String" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Left" << endl;
        cout << "5. Right" << endl;
        cout << "6. Display" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter character: ";
                cin >> ch;
                t.insert(ch);
                break;
            case 2:
                cout << "Enter string: ";
                cin >> str;
                t.insertString(str);
                break;
            case 3:
                t.del();
                break;
            case 4:
                t.left();
                break;
            case 5:
                t.right();
                break;
            case 6:
                t.display();
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}
