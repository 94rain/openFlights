# liwens3-yihanz8-zhekaig2-sji15

## Document files
* [Team Contract](CONTRACT.md)
* [Project Proposal](Project_Proposal.md)
* [Development Log](Development_Log.md)

## Building the program
1. Clone the project repository to your local machine
2. `cd liwens3-yihanz8-zhekaig2-sji15`
3. Enter the command `make` in the terminal

## Running the program

After building the program, run `./openflight` in the terminal

## Testing the program

1. To build the tests, run the command `make test`
2. run `./test` for comprehensive tests
    - To test parts of the program:
      - run `./test [graph]` for OpenFlight graph basic tests
      - run `./test [class]` for classes (Airport and Route) constructor and getters tests
      - run `./test [bfs]` for BFS algorithm tests
      - run `./test [dataset=n]` (n=1,2) for BFS algorithm tests