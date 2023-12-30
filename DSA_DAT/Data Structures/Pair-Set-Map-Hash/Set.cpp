#include <iostream>
#include <vector>

using namespace std;

// dung tu tuong cua merge
struct node
{
    int value;
    node *next;

    node()
    {
        next = NULL;
    }

    node(int value)
    {
        this->value = value;
        next = NULL;
    }
};

struct Set
{
private:
    node *head; // bien cam canh
public:
    Set()
    {
        head = new node;
        head->next = NULL;
    }

    bool empty()
    {
        if (head->next == NULL)
            return true;
        return false;
    }

    // chèn giá trị x vào Set khi x chưa xuất hiện.
    // duyệt list đến khi nào x nhỏ hơn 1 giá trị nào đó.
    void insert(int x)
    {
        node *n = new node(x);
        if (empty())
            head->next = n;
        else
        {
            node *it = head;
            while (true)
            {
                if (it->next != NULL)
                {
                    if (it->next->value > x)
                    {
                        node *tmp = it->next;
                        n->next = tmp;
                        it->next = n;
                        return;
                    }
                    else if (it->next->value == x)
                    {
                        return; // khi đã tồn tại giá trị x
                    }
                    else
                    {
                        it = it->next;
                    }
                }
                else
                {
                    // khi set chưa có giá trị nào hoặc đã duyệt hết set
                    // khi đó có 2th là node ở đầu hoặc ở cuối
                    it->next = n;
                    return;
                }
            }
        }
    }

    void erase(int x)
    {
        node *it = head;
        while (it->next != NULL)
        {
            if (it->next->value == x)
            {
                node *tmp = it->next->next;
                delete it->next;
                it->next = tmp;
                return;
            }
            else
            {
                it = it->next;
            }
        }
    }

    void print()
    {
        if (empty())
        {
            cout << "Empty Set!\n";
            return;
        }
        node *it = head->next;
        cout << "Set: ";
        while (it != nullptr)
        {
            cout << it->value << " ";
            it = it->next;
        }
        cout << endl;
    }

    // Hợp 2 tập hợp, giống Merge 2 danh sách liên kết
    Set Union(Set &s)
    {
        Set res;
        node *it1 = head->next; // con trỏ trỏ đến phần tử đầu danh sách 1
        node *it2 = s.head->next;// con trỏ trỏ đến phần tử đầu danh sách 2

        while (it1 != NULL && it2 != NULL)
        {
            if (it1->value < it2->value)
            {
                res.insert(it1->value);
                it1 = it1->next;
            }
            else if (it1->value > it2->value)
            {
                res.insert(it2->value);
                it2 = it2->next;
            }
            else
            {
                res.insert(it1->value);
                it1 = it1->next;
                it2 = it2->next;
            }
        }

        while (it1 != NULL)
        {
            res.insert(it1->value);
            it1 = it1->next;
        }

        while (it2 != NULL)
        {
            res.insert(it2->value);
            it2 = it2->next;
        }
        return res;
    }

    // Giao 2 tập hợp, chỉ lấy những phần tử giống nhau( = nhau)
    Set Intersection(Set &s)
    {
        Set res;
        node *it1 = head->next;
        node *it2 = s.head->next;

        while (it1 != NULL && it2 != NULL)
        {
            if (it1->value < it2->value)
            {
                it1 = it1->next;
            }
            else if (it1->value > it2->value)
            {
                it2 = it2->next;
            }
            else
            {
                res.insert(it1->value);
                it1 = it1->next;
                it2 = it2->next;
            }
        }
        return res;
    }

    // Hiệu 2 tập hợp
    Set Difference(Set &s)
    {
        Set res;
        node *it1 = head->next;
        node *it2 = s.head->next;

        while (it1 != NULL && it2 != NULL)
        {
            if (it1->value < it2->value)
            {
                res.insert(it1->value);
                it1 = it1->next;
            }
            else if (it1->value > it2->value)
            {
                it2 = it2->next;
            }
            else
            {
                it1 = it1->next;
                it2 = it2->next;
            }
        }

        while (it1 != NULL)
        {
            res.insert(it1->value);
            it1 = it1->next;
        }
        return res;
    }
};

int main()
{
    vector<int> value = {1, 5, 8, 11, 6, 6, 8};
    vector<int> value2 = {1, 2, 3, 6, 7, 8, 8, 10};
    Set s1;
    for (int i : value)
    {
        s1.insert(i);
    }
    s1.print();
    Set s2;
    for (int i : value2)
    {
        s2.insert(i);
    }
    s2.print();
    Set s3 = s2.Difference(s1);
    s3.print();
}

// /*
// #include <iostream>
// #include <set>
// #include <unordered_set>

// using namespace std;

// /*
//     SET:- tập hợp mà không cho phép có 2 phần tử giống nhau,
//         tất cả phải đều là riêng biệt
//         - Độ phức tạp: O(logn)
//         - Tự sắp xếp tăng dần
//         - Không thể truy cập trực tiếp vào phần tử
//         - Không thể thay đổi giá trị phần tử
//         - Có thể xóa phần tử = erase(id)
//         - Có thể thêm phần tử = insert(x)
//         - Có thể tìm kiếm phần tử = find(x)
//         - Có thể đếm số lượng phần tử = count(key) trả về số lần xuất hiện khóa key
//         - Có thể xóa tất cả phần tử = clear()
//         - Có thể kiểm tra rỗng = empty()
//         - Có thể lấy kích thước = size()
//         - Có thể duyệt = for(auto i : s) cout << i << " ";
//         - Có thể duyệt = for(auto i = s.begin(); i != s.end(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.rbegin(); i != s.rend(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.cbegin(); i != s.cend(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.crbegin(); i != s.crend(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.lower_bound(x); i != s.upper_bound(x); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.find(x); i != s.end(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.cfind(x); i != s.cend(); i++) cout << *i << " ";
//         - Có thể duyệt = for(auto i = s.rfind(x); i != s.rend(); i++) cout << *i << " ";
//    MULTISET: 
//         - tập hợp có thể có 2 phần tử giống nhau
//         - Độ phức tạp: O(logn)
//         - Tự sắp xếp tăng dần
//    UNORDERED_SET:
//         - tập hợp mà không cho phép có 2 phần tử giống nhau,
//         tất cả phải đều là riêng biệt
//         - Độ phức tạp: O(1)
//         - Không tự sắp xếp
// */

// int main()
// {
//     // khai báo
//     // set<data_type1, data_type2> s;
//     set<int> s;

//     // thêm phần tử vào set
//     // s.insert(value . . .);
//     s.insert(1);
//     s.insert(3);
//     s.insert(5);

//     // đếm số lượng phần tử
//     s.size();

//     // con trỏ trỏ đến phần tử đầu và phần tử cuối
//     // s.begin() và s.rbegin()
//     cout << *s.begin() << " " << *s.rbegin() << endl;

//     // tìm kiếm
//     // find(value) hoặc count(value)
//     if (s.count(5) != 0)
//         cout << "Found\n";
//     if (s.find(5) != s.end())
//         cout << "found\n";

//     // Hàm xóa
//     // s.erase(value) hoặc s.erase(s.find(value))
//     s.erase
// }
