/*
 * @Author: your name
 * @Date: 2021-04-17 20:09:12
 * @LastEditTime: 2021-04-17 20:42:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /cs225git/mnt/f/sp21/liwens3-yihanz8-zhekaig2-sji15/main.cpp
 */
#include "OpenFlight.h"
#include "algorithm/BFS.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

//int main(int argc, const char * argv[]) {
int main() {
  // how to use getAjacentRoute, pass a code of an airport

//   OpenFlight o1("data/simple_airports_1.csv", "data/simple_routes_1.csv", "1");
  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv", "6156");
  BFS s;
  auto path = s.getPath(o1);
  cout << s.getCount() << endl;
  for (auto p : path) {
    cout << p.getName() << endl;
  }
  cout << path[0].getName() << endl;
}
