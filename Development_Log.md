<h1 align="center">Development Log</h1>

## April 5, 2021 - April 11, 2021
  In the first week, we decided to use the OpenFlight as our dataset and implement BFS traversal, Dijkstra's algorithm, and PageRank algorithm in a directed graph. Moreover, everyone signed the contract and drew up the project proposal. At the same time, we have split up an equal workload to everyone. 

## April 12, 2021 - April 18, 2021
  We built the basic graph framework for our project. During the time, we met some trouble on how to parse airport data to our graph, but finally, we fixed these bugs.
  We implemented `route` as our graph's edge, `airport` as our graph's node, and `Openflight` classes as our final graph. Liwen Sun added MakeFile and implemented our first algorithm BFS. Shuyang Ji added basic test cases for the Openflight graph and BFS. They updated README to include necessary commands for compiling, running, and testing our project.

## April 19, 2021 - April 25, 2021
  We implement the `Dijkstra` class. It includes a constructor and two methods `get_path`, and `get_distance`. The constructor accepts a starting airport and calculates the shortest distance between all of the other airports and the start point storing it into a map. Then get_path and get_distance methods would accept the Airport format of destination and return the corresponding value (distance and the best path to the destination). We also implement some basic tests for this class and run on the total dataset.  Zhekai Ge implemented Dijkstra.h and Dijkstra.cpp and Yihan Zhang added the test cases for the algorithm.


## April 26, 2021 - May 2, 2021
  We decided to change our third algorithm PageRank since it will create a large 7000 * 7000 huge matrix multiplication on the actual dataset which will take 25 mins to produce the final results. After our consideration, we will implement the A* algorithm as our third algorithm. When we were implementing this algorithm, the most difficult part is how to understand the heuristic function of AStar. Liwen Sun was responsible for implementing the main part of AStar. Then Zhekai Ge optimized our codes, making them efficient on the actual dataset. Shuyang Ji and Yihan Zhang added test cases for this algorithm.

## May 3, 2021 - May 9, 2021
  We started to work on the main program and modify some details in the code. We added the command line arguments that allow for selecting the algorithm used to find the shortest path in the command line prompt. We also check whether the input is valid and provide options for exiting the program. We added additional test cases to ensure the correctness of our program (including tests in disconnected and cyclic graph). We wrote a initial draft for the project results. Also, we finished the final presentation video.

## May 10, 2021 - May 12, 2021
  In the final week, we confirmed that we have answered the ‘leading question’ we were hoping to solve. Reflecting on what achievements we have made, what unexpected outcomes and discoveries we have found, and what challenges we have overcome, we completed writing up the project results, finished the final presentation video and polished our documentation.