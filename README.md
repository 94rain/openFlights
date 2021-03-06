<h1 align="center"> CS 225 Final Project</h1>
<h3 align="center"> liwens3-yihanz8-zhekaig2-sji15 </h3>

## Document files
* [Team Contract](CONTRACT.md)
* [Project Proposal](Project_Proposal.md)
* [Development Log](Development_Log.md)
* [Results](Results.md)

## Directory structures
* Algorithms: `algorithm/*`
  * [AStar.h](algorithm/AStar.h) · [AStar.cpp](algorithm/AStar.cpp)
  * [BFS.h](algorithm/BFS.h) · [BFS.cpp](algorithm/BFS.cpp)
  * [Dijkstra.h](algorithm/Dijkstra.h) · [Dijkstra.cpp](algorithm/Dijkstra.cpp)
* data: `data/*`
  * [airports.csv](data/airports.csv) · [routes.csv](data/routes.csv)
  * simple_airports_n.csv · simple_routes_n.csv (n=1,2,3,4,5 smaller datasets)
* tests: `tests/*`
  * [test_AStar.cpp](tests/test_AStar.cpp) · [test_BFS.cpp](tests/test_BFS.cpp) · [test_Dijkstra.cpp](tests/test_Dijkstra.cpp) · [test_graph.cpp](tests/test_graph.cpp)

## Video
[View our presentation on YouTube](https://youtu.be/Ge6wcQfbpuE)

## Building the program
1. Clone the project repository
2. `cd liwens3-yihanz8-zhekaig2-sji15`
3. Run the command `module load llvm/6.0.1` on EWS
4. Enter the command `make` in the terminal

## Running the program

1. After building the program, run `./openflight` in the terminal.

2. The terminal prompt will ask you to select the dataset in which you hope to find the shortest path. You can also choose to customize input datasets by inputting the relative file paths.

    ![image](assets/example_choose_dataset.png)

3. There will appear 3 options `1. BFS`, `2. Dijkstra`, `3. A*`. Choose one of the algorithms by entering the number `1`, `2` or `3`.

    ![Image text](assets/example_choose_algorithm.png)

4. Then, the terminal will ask you to enter the ID of starting airport and ending airport (Just type the ID with numbers like `302`).

    ![Image text](assets/example_set_airport.png)

5. Finally, the program will use the chosen algorithm to calculate the shortest path from the starting airport to the ending airport and print out the corresponding airport IDs and names along the path including the start and end point. The result will look like this:

    ![Image text](assets/example_result.png)
  
6. In the end, you can enter `exit` to exit the program, or run another algorithm if you wish.

    ![Image text](assets/example_exit.png)

## Testing the program

1. To build the tests on EWS, run the command `module load llvm/6.0.1` and then enter `make test`.
2. run `./test` for comprehensive tests
    - To test parts of the program:
      - run `./test [graph]` for OpenFlight graph basic tests
      - run `./test [bfs]` for BFS algorithm tests
      - run `./test [dataset=n]` (n=1,2,3,4,5) for testing individual datasets
      - run `./test [dijkstra]` for Dijkstra's Algorithm tests
      - run `./test [astar]` for A* Algorithm tests

