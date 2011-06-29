#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<iomanip>
#include<queue>
#include<math.h>
#include<vector>
using std::vector;
using std::priority_queue;

#include <sys/time.h>
#define NUM_POINTS 10
#define DEBUG 0

struct Point {
	int x;
	int y;
	int z;
	Point(int xp,int yp,int zp) { x=xp;y=yp;z=zp; }
	Point() {}
};

class ComparePoint {
	Point origin;
	public:
		bool operator()(Point* p1, Point* p2 ) {
			long d1x = (p1->x - origin.x);
			long d1y = (p1->y - origin.y);
			long d1z = (p1->z - origin.z);	
		
			long d2x = (p2->x - origin.x);
			long d2y = (p2->y - origin.y);
			long d2z = (p2->z - origin.z);	
			long d1 = ((d1x*d1x)+(d1y*d1y)+(d1z*d1z));
		        long d2 = ((d2x*d2x)+(d2y*d2y)+(d2z*d2z));
#if DEBUG		
			cout <<"Point P1: "<<d1x<<d1y<<d1z<<endl;	
			cout <<"Point P2: "<<d2x<<d2y<<d2z<<endl;	
#endif
			return d1 <  d2;
		}
		ComparePoint() { origin.x = origin.y = origin.z = 0; }	
};

typedef priority_queue<Point*,vector<Point*>,ComparePoint> pQueue;

int diff_ms(timeval t1, timeval t2)
{
	    return (((t1.tv_sec - t2.tv_sec) * 1000000) + 
			                (t1.tv_usec - t2.tv_usec))/1000;
}

/* Insert only if the Point is nearer than the Top*/
void compareAndInsert(pQueue &Q,Point &p) {
	ComparePoint check;
	if(Q.size()) {
		Point *top = Q.top();
		if(check(top,&p) == true)
			return;
	}
	Q.push(new Point(p.x,p.y,p.z));
}	
int main() {
	pQueue Q;
	int x,y,z;
	timeval t1,t2;
	Point point;
	while(1) {
		cin>>point.x>>point.y>>point.z;
		if(cin.fail())
			break;
#if DEBUG
		gettimeofday(&t1,NULL);
#endif
		compareAndInsert(Q,point);
#if DEBUG
		gettimeofday(&t2,NULL);
		//cout<<"Push Time: "<<diff_ms(t2,t1)<<endl;
#endif
		if(Q.size() > NUM_POINTS)
			Q.pop();
	}	
	int i = 0;
	cout<<"Processing stopped at :"<<point.x<<endl;
	cout<<"###### Top Ten ######"<<endl;
	while(Q.size() > 0) {
		Point *p = Q.top();
		cout<<"Point["<<i<<"] -> ("<<p->x<<","<<p->y<<","<<p->z<<")"<<endl;
		i++;
		Q.pop();
	}	
}
