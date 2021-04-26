<h1 align="center">Development Log</h1>

## April 5, 2021 - April 11, 2021
  At the first week, we decided to use the OpenFlight as our dataset and implement BFS traversal, Dijkstra's algorithm and PageRank algorithm in a directed graph. Moreover, everyone signed up the contract and drew up project proposal. At the same time, we have splitted up equal workload to everyone. 

## April 12, 2021 - April 18, 2021
  We built the basic graph framwork for our project. During the time, we met some trouble on how to parse airport data to our graph, but finally we fixed these bug.
  We implemented route as our graph's edge, airport as our graph's node and Openflight as our final graph. Liwen Sun added MakeFile and implemented our first algorithm BFS. Shuyang Ji added basic test cases for Openflight graph and BFS. They updated README to include necessary commands for compiling, runing and testing our project.

## April 19, 2021 - April 25, 2021
  We implement the Dijkstra class. It includes three methods, the constructor, get_path and get distance. The constructor accepts a starting airport and calculate the shortest distance between all of the other airports and the start point storing it into a map. Then get_path and get_distance methods would accept the Airport format of destination and return the coresponding value(distance and the best path to the destination). Zhekai Ge implemented Dijkstra.h and Dijkstra.cpp and Yihan Zhang added the test cases for the algorithm.


## April 26, 2021 - May 2, 2021
- [ ] Implement PageRank Algorithm
