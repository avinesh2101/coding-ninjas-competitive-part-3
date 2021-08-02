#include<bits/stdc++.h>
using namespace std;

class Point{
    public:
        double x,y;
};

class Polygon{
    public:
        Point*points;
        Polygon(int npoints){  //constructor
            
            points = new Point[npoints];
        }
};

double area(Polygon p,int n)
{//A(x1,y1) B(x2,y2) C(x3,y3)
// AB (X1,Y1)= (x2-x1,y2-y2) , AC(X2,Y2)=(x3-x1,y3-y1)
//AB x AC = X1*Y2 - Y1*X2,Croos product

    double fArea =0;

    for(int i=0;i<n-1;i++)
    {
        double x1 = p.points[i].x - p.points[0].x;
        double x2 =p.points[i].y - p.points[0].y;
        double y1 =p.points[i+1].x - p.points[0].x;
        double y2 =p.points[i+1].y - p.points[0].y;
        double cross_p = x1*y2 - y1*x2;
        fArea += cross_p;
    }
    return abs(fArea/2);
}

int main()
{
    cout<<"Enter the no. of points for polygon"<<endl;
    int n;
    cin>>n;
    Polygon p(n);
    cout<<"Enter the coordinates for polygon "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>p.points[i].x;
        cin>>p.points[i].y;   
    }

    cout<<"Area of polygon is "<<area(p,n) <<endl;

    return 0;
}