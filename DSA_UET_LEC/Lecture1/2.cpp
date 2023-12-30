#include<iostream>

using namespace std;

class Point{
public:
    double x, y;

    Point(double x_ = 0, double y_ = 0){
        x = x_;
        y = y_;
    }

    void printf(){
        cout << x << " " << y << endl;
    }
};

double Det_x_, Det_y_, Det_;

class Line{
public:
    Point p1, p2;

    Line(const Point& p1_, const Point& p2_){
        p1 = p1_;
        p2 = p2_;
    }

    static bool checkConditionLine(const Line& l1, const Line& l2){
        double a1 = l1.p1.y - l1.p2.y;
        double b1 = l1.p2.x - l1.p1.x;
        double c1 = l1.p2.x*l1.p1.y - l1.p1.x*l1.p2.y;

        double a2 = l2.p1.y - l2.p2.y;
        double b2 = l2.p2.x - l2.p1.x;
        double c2 = l2.p2.x*l2.p1.y - l2.p1.x*l2.p2.y;

        double Det = a1*b2 - a2*b1;
        double Det_x = c1*b2 - c2*b1;
        double Det_y = a1*c2 - a2*c1;

        Det_ = Det;
        Det_x_ = Det_x;
        Det_y_ = Det_y;

        return Det == 0;
    }

    static Point checkTwoLine(const Line& l1, const Line& l2){
        if(checkConditionLine(l1, l2)){
            if(Det_x_ == 0 && Det_y_ == 0){
                return Point(0, 0); //MANY
            }else{
                return Point(1, 1); //NO
            }
        }else{
            double x = Det_x_/Det_;
            double y = Det_y_/Det_;
            return Point(x, y);
        }
    }
};

int main(){
    Point A, B, C, D;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    Line AB(A, B);
    Line CD(C, D);

    Point ans = Line::checkTwoLine(AB, CD);
    if(ans.x == 0 && ans.y == 0) cout << "MANY\n";
    else if(ans.x == 1 && ans.y == 1) cout << "NO\n";
    else
        ans.printf();

    return 0;
}