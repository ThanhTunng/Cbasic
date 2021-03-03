#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
  double x;
  double y;
}point;

typedef struct circle{
  point center;
  double radius;
}circle;
 
int check(point p, point c,double r){
  double a = (c.x-p.x)*(c.x-p.y) + (c.y-p.y)*(c.y-p.y);
  double distance = sqrt(a);
  if(distance < r) return -1;
  else if(distance == r) return 0;
  else return 1;
}

int main()
{
  double r;
  point p;
  circle c;
  printf("Enter the co-ordinate of point A: ");
  scanf("%lf %lf", &p.x, &p.y);
  /* printf("Enter the co-ordinate of point B: "); */
  /* scanf("%lf lf", &p[1].x, &p[1].y) */
  printf("Enter the co-ordinate of the center of the circle: ");
  scanf("%lf %lf", &c.center.x, &c.center.y);
  printf("Enter the radius of the circle: ");
  scanf("%lf", &c.radius);
  printf("%d\n", check(p,c.center,r));
  return 0;
}
