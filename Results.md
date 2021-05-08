<h1 align="center"> CS 225 Final Project Result </h1>

## Overview





## Implementations

### Breadth First Search

The first algorithm we implemented the Breadth First Search. In our project, we use this algorithm to search each airport from source to destination.
To avoid processing a node more than once, we use an `unordered_map` (key: Airport, value: True if the airport has been explored, false otherwise) to mark explored airports.
We use a `queue` that contain the frontier airports along which the algorithm is currently searching. 
The simple BFS is only appliable when the graph is connected. To make it work on disconnected graph, we modified the algorithm to perform BFS from each unvisited airport.
To test the correctness of our BFS algorithm, we developed test cases on five smaller datasets (including simple, complex cycles and disconnected graphs) and checked whether the output path is same as the expected path.
#### Methods

`vector<Airport> getPath(OpenFlight graph)` get the path of all visited airports during BFS traversal

`int getCount()` get the number of visited airports during BFS traversal

`Airport getEnd()` get the ending airport after BFS traversal

#### Examples

**Simple Cycle** (Sample #1): 4 is the starting point. 

Path of the traversed airports (ID): 4, 2, 1, 3
<img src="assets/bfs_testcase1_1.png" alt="image-20210506173850837" style="zoom: 50%;" />![image-20210506174729338](assets/bfs_testcase1_2.png)



**Complex Cycle** (Sample #2):
Path of the traversed airports (ID): 2922, 6969, 2975, 2990, 2965, 6156, 2979
<img src="assets/bfs_testcase2_1.png" alt="image-20210506184754023" style="zoom: 50%;" /><img src="assets/bfs_testcase2_2.png" alt="image-20210506175018273" style="zoom: 67%;" />

**Disconnected graph** (Sample #5):
Path of the IDs of traversed airports (ID): 9481, 8335, 6435, 3395, 3393
<img src="assets/bfs_testcase5_1.png" alt="image-20210506185235021" style="zoom:67%;" /> <img src="assets/bfs_testcase5_2.png" style="zoom:80%;" />

### Dijkstra's Algorithm

### A* Search
A* is an informed search algorithm. In our project, it starts from a specific starting airport and aims to find a path to the target airport having the least cost.
At each iteration of its main loop, we use priority queue to select the airport that minimizes
                                                                    f(n) = g(n) + h(n)
where n is the next airport on the path, g(n) is the route distance from source airport to n. h(n) is a heuristic function that estimates the shortest distance from n to the target airport. 
Then we compute its neighours’ corresponding f(n) and compare their new f(n) with their original f(n). If new f(n) is smaller than original f(n), then we update its neighours’ f(n) and add its neighbours to our priority queue. Moreover, we record the previous airport to reconstruct our path. If the airport we pop from our priority queue is our target, then we finished our search. If the priority queue is empty and our targret still is never reached, this means there does not exists route between source and destination airport.

Application on full dataset:
In this example, we choose Goroka Airport as our source and London Gatwick Airport as our destination.
![Astar_testcase1_1](assets/Astar_testcase1_1.png)
If we choose disconnected airports, A* search will provide error messages accordingly.
![Astar_testcase1_2](assets/Astar_testcase1_2.png)

<img src="assets/Astar_testcase1_3.png" alt="Astar_testcase1_3" style="zoom:67%;" />



![Astar_testcase1_4](assets/Astar_testcase1_4.png)



