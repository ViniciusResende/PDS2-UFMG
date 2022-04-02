/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include <algorithm>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
  const std::vector<Point> lhs_coordinates = lhs;
  const std::vector<Point> rhs_coordinates = rhs;
  
  // for (Point point : lhs_coordinates) {
  //   if(std::find(rhs_coordinates.begin(), rhs_coordinates.end(), point) == rhs_coordinates.end())
  //     return false;
  // }

  // for (Point point : rhs_coordinates) {
  //   if(std::find(lhs_coordinates.begin(), lhs_coordinates.end(), point) == lhs_coordinates.end())
  //     return false;
  // }
  bool firstCondition = true;
  for (const Point point : lhs_coordinates) {
    firstCondition = true;
    for (const Point point2 : rhs_coordinates) {
      if(point.contains(point2)) {
        firstCondition = false;
        break;
      }
    }
    if(firstCondition) return false;
  }


  for (const Point point2 : rhs_coordinates) {
    firstCondition = true;
    for (const Point point : lhs_coordinates) {
      if(point2.contains(point)) {
        firstCondition = false;
        break;
      }
    }
    if(firstCondition) return false;
  }
  
  return true;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
  int menorx = 999999;
  int maiorx = -999999;
  int menory = 999999;
  int maiory = -999999;
  for (Point point : this->limits) {
    if(point.x > maiorx)
      maiorx = point.x;

    if(point.x < menorx)
      menorx = point.x;

    if(point.y > maiory)
    maiory = point.y;

    if(point.y < menory)
      menory = point.y;
  }


  return (p.x > menorx && p.x < maiorx) && (p.y > menory && p.y < maiory);
}

Point::Point(int xx, int yy): x(xx), y(yy) {
  this->limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  Point p0(x0, y0);
  this->limits.push_back(p0);

  Point p1(x0, y1);
  this->limits.push_back(p1);

  Point p2(x1, y0);
  this->limits.push_back(p2);

  Point p3(x1, y1);
  this->limits.push_back(p3);
}