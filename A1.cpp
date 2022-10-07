#include <iostream>
using namespace std;

// Khai bao ctdl
struct Node
{
    int Data;
    Node *pNext;
};
typedef struct Node NODE;

struct List
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct List LIST;

// Khoi tao danh sach
void Init(LIST &l)
{
    l.pHead = l.pTail = NULL;
}

// Tao Node
NODE *TaoNode(int x)
{
    // Cấp phát 1 Node
    NODE *p = new NODE;
    if (p == NULL)
    {
        return NULL;
    }
    p->Data = x;     // Lưu x vào data
    p->pNext = NULL; // Khởi tạo mối liên kết
    return p;
}

// Thêm Node p vào đầu danh sách
void AddHead(LIST &l, NODE *p)
{
    if (l.pHead == NULL) // Tức là danh sách bị rỗng
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead; // p quăng dây để tham gia vào danh sách
        l.pHead = p;        // p chính thức đã đứng dầu danh sách
    }
}

// Thêm Node p vào cuối danh sách
void AddTail(LIST &l, NODE *p)
{
    if (l.pHead == NULL) // Tức là danh sách bị rỗng
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p; // l.pTail quăng dây nối với p
        l.pTail = p;
    }
}

// Nhap du lieu
void InPut(LIST &l)
{
    int n;
    cout << "Nhap so luong node: ";
    cin >> n;
    Init(l);
    cout << "Nhap du lieu so: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        NODE *p = TaoNode(x);
        AddTail(l, p);
    }
}

void OutPut(LIST l)
{
    cout << "Du lieu vua nhap la: ";
    for (NODE *p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->Data << " ";
    }
}

int TimMax(LIST l)
{
    int MAX = l.pHead->Data;
    for (NODE *p = l.pHead->pNext; p != NULL; p = p->pNext)
    {
        if (p->Data > MAX)
            MAX = p->Data;
    }
    return MAX;
}

int main()
{
    system("cls");

    LIST l;
    InPut(l);
    OutPut(l);

    int Max = TimMax(l);

    cout << "\nMax la: " << Max;

    cout << "\n";
    system("Pause");
}