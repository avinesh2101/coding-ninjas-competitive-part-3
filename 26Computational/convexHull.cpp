#include <iostream>
#include <vector>
using namespace std;
//----------------method-1:Jarvis algorithm  TC - O(n^2) --------------------------------
// int this method we will find the left most point P  in the given points and then
// take a point q=(p+1) %n and check it with all r 
// pq x qr > 0  then we add line in hull from p to r and change q to r and move on 
//after checking all elements change q with p and do so until p not becomes equal to the first time 
//selected P i.e is the leftmost P
struct point
{
    int x, y;
};
bool crosser(point p, point q, point r)
{
    int x1 = q.x - p.x;
    int y1 = q.y - p.y;
    int x2 = r.x - q.x;
    int y2 = r.y - q.y;
    int value = x1 * y2 - y1 * x2;
    return value < 0; //will change only when the cross prod is greater than 0
    //if the cross product is =0, then the points are colinear.
}
void convex_hull(point *points, int n)
{
    //step1. find the leftmost element i.e smallest vlaue of x
    vector<point> hull;
    int left = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[left].x)
        {
            left = i;
        }
    }
    //now left contains the index of the left most point
    int p = left;
    
    
    //step 2;
    do
    {
        hull.push_back(points[p]);
        int q = (p + 1) % n; //so that it loops over the array(circular array)
        for (int i = 0; i < n; i++)// pq x qr , i is working as r here
        {
            if (crosser(points[p], points[q], points[i]))
            {
                q = i;
            }
        }
        p = q;
    } while (p != left);
    for (auto i : hull)
    {
        cout << i.x << " " << i.y << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr_x = new int[n];
    int *arr_y = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr_x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr_y[i];
    }
    point *points = new point[n];
    for (int i = 0; i < n; i++)
    {
        point p;
        p.x = arr_x[i];
        p.y = arr_y[i];
        points[i] = p;
    }
    convex_hull(points, n);
    delete [] arr_x;
    delete [] arr_y;
    delete [] points;
}








// ---------------------------method2: Graham's Algorithm TC- O(n logn)------------------
//in this algo 
//•Start with the lowest point (anchor point) and Now, form a closed simple path traversing the
// points by increasing angle with respect to the anchor point
//• Form a simple polygon (connect the dots as before)
//• Remove points at concave angles
// keep the path and the hull points in two sequences
// • elements are removed from the beginning
// of the path sequence and are inserted and
// deleted from the end of the hull sequence
// • orientation is used to decide whether to accept or reject the next point
//source http://www.dcs.gla.ac.uk/~pat/52233/slides/Hull1x1.pdf
// https://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/
/*
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
 
struct Point
{
    int x, y;
};
 
// A global point needed for  sorting points with reference
// to  the first point Used in compare function of qsort()
Point p0;
 
// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
// A utility function to swap two points
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
// A utility function to return square of distance
// between p1 and p2
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   // Find orientation
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 
// Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
   // Find the bottommost point
   int ymin = points[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = points[i].y;
 
     // Pick the bottom-most or chose the left
     // most point in case of tie
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   // Place the bottom-most point at first position
   swap(points[0], points[min]);
 
   // Sort n-1 points with respect to the first point.
   // A point p1 comes before p2 in sorted output if p2
   // has larger polar angle (in counterclockwise
   // direction) than p1
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   // If two or more points make same angle with p0,
   // Remove all but the one that is farthest from p0
   // Remember that, in above sorting, our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle.
   int m = 1; // Initialize size of modified array
   for (int i=1; i<n; i++)
   {
       // Keep removing i while angle of i and i+1 is same
       // with respect to p0
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;
 
 
       points[m] = points[i];
       m++;  // Update size of modified array
   }
 
   // If modified array of points has less than 3 points,
   // convex hull is not possible
   if (m < 3) return;
 
   // Create an empty stack and push first three points
   // to it.
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   // Process remaining n-3 points
   for (int i = 3; i < m; i++)
   {
      // Keep removing top while the angle formed by
      // points next-to-top, top, and points[i] makes
      // a non-left turn
      while (S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
   // Now stack has the output points, print contents of stack
   while (!S.empty())
   {
       Point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}
 
// Driver program to test above functions
int main()
{
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
*/