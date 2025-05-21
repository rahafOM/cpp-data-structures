#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // إضافة عنصر في نهاية القائمة
    void AddToLast(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = newNode;
    }

    // إضافة عنصر في بداية القائمة باستخدام الرأس فقط
    void AddToFirst(int val)
    {
        Node *n = new Node(val);
        n->next = head;
        head = n;
    }
    // اضافة عنصر حسب  الاندكس
    void insertAt(int index, int val)
    {
        if (index < 0 || index > size())
        {
            cout << "invalid index :(" << endl;
            return;
        }
        if (index == 0)
        {
            AddToFirst(val);
            return;
        }
        Node *p = head;
        int currentIndex = 0;
        // التنقل إلى العنصر السابق للمكان المطلوب
        while (p != nullptr && currentIndex < index - 1)
        {
            p = p->next;
            currentIndex++;
        }
        if (p == nullptr)
        {
            cout << "Index out of bounds.\n";
            return;
        }
        Node *n = new Node(val);
        n->next = p->next;
        p->next = n;
    }
    void removeAt(int index)
    {
        if (index < 0 || head == nullptr)
        {
            cout << "Invalid index" << endl;
            return;
        }

        // حذف أول عنصر
        if (index == 0)
        {
            deleteFromFirst();
            return;
        }
        Node *p = head;
        int currentIndex = 0;

        // الوصول إلى العقدة السابقة للمطلوب حذفها
        while (p->next != nullptr && currentIndex < index - 1)
        {
            p = p->next;
            currentIndex++;
        }
        if (p->next == nullptr)
        {
            cout << "Index out of bounds.\n";
            return;
        }

        Node *nodeToDelete = p->next;
        p->next = p->next->next;
        delete nodeToDelete;
    }
    // حذف أول عنصر
    void deleteFromFirst()
    {
        if (head == nullptr)
            return;
        Node *p = head;
        head = head->next;
        delete p;
    }

    // حذف آخر عنصر
    void deleteFromLast()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *p = head;
        while (p->next->next != nullptr)
        {
            p = p->next;
        }
        delete p->next;
        p->next = nullptr;
    }

    // البحث عن عنصر
    bool search(int key)
    {
        Node *p = head;
        while (p != nullptr)
        {
            if (p->data == key)
                return true;
            p = p->next;
        }
        return false;
    }
    // مجموع العناصر
    int sum()
    {
        int total = 0;
        Node *p = head;
        while (p != nullptr)
        {
            total += p->data;
            p = p->next;
        }
        return total;
    }
    // تفريغ القائمة
    void clear()
    {
        while (head != nullptr)
        {
            deleteFromFirst();
        }
    }
    // طباعة القائمة
    void printList()
    {
        Node *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "NULL" << endl;
    }

    // عدد العناصر == حساب طول القائمة
    int size()
    {
        int count = 0;
        Node *p = head;
        while (p != nullptr)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    // تفريغ القائمة عند الانتهاء
    ~LinkedList()
    {
        while (head != nullptr)
        {
            deleteFromFirst();
        }
    }
};
int main()
{
    LinkedList list;

  
    list.AddToLast(10);
    list.AddToLast(20);
    list.AddToLast(30);
    list.printList();  // 10 20 30 NULL


    list.AddToFirst(5);
    list.AddToFirst(2);
    list.printList();  // 2 5 10 20 30 NULL

   
    list.insertAt(2, 99);
    list.printList();  // 2 5 99 10 20 30 NULL

    list.removeAt(3);
    list.printList();  // 2 5 99 20 30 NULL

  
    cout << (list.search(20) ? "found " : "Not Found") << endl;

    cout << list.sum() << endl;

    list.deleteFromFirst();
    list.printList();  // 5 99 20 30 NULL


    list.deleteFromLast();
    list.printList();  // 5 99 20 NULL

    cout << list.size() << endl;

    list.clear();
    list.printList();  // NULL

    return 0;
}
