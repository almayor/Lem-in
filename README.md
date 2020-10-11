# lem-in

*This project is part of the official curriculum at [School 42](https://en.wikipedia.org/wiki/42_(school)).*

## Disclaimer

> At [School 42](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written to comply with a coding standard (also known as the "[Norm](./docs/subjects/norme.en.pdf)"). As a result, the implementation of certain parts may appear strange.

## Overview

* [Official instructions](docs/subjects/lem-in.en.pdf)
* [Code documentation](https://almayor.github.io/lem-in)
* This project practices the following algorithmic topics
	* minimum cost maximum flow (Ford-Fulkerson, Suurballe)
	* path search in directed graphs (BFS, Dijkstra, Bellman-Ford)
	* sorts (quick sort, insertion sort)
	* efficient data representation (priority quues, graphs, arrays, queues, linked lists)

## Run

To compile, run

```sh
git clone https://github.com/almayor/lem-in
cd lem-in
git submodule --init --recursive
make
```
Then try some example maps

```sh
./lem-in < example-maps/flow-thousand.txt
```
or generate your own

```sh
./generator --flow-thousand | ./lem-in
```

(_NOTE_ that the `generator` has only been made available to us in a Linux compilation.)

## Test

Your can check that a generated solution is correct using the provided Python script `check-solution`

```sh
./lem-in < {your-map} | ./check-solution
```

Alternatively, you can run the whole batch of included tests with

```sh
make test
```
## Algorithm

_(All observation are true to our particular case, where all edges and nodes, other than `start` and `end`, have a unit positive capacity)_

### Minimum cost for a given flow 

**Defition:** Flow constraints are constraints stipulating that at every node other than `start` an `end`, the amount of incoming flow equals the amount of outgoing flow.

Note that in our particular case, any path from `start` to `end` or a closed path, such as a cycle, automatically satisfies the flow constrains.

**Defition:** A residual network _Gr_ is formed from a network _G_ by replacing all edges along paths involved in a flow _f_ with edges directed in the opposite direction to the flow, and negating their cost.

**Observation:** A cycle in the residual graph _Gr_ doesn't change the value of the flow in the graph _G_. Moreover, the cost of the flow changes in relation to the cost of the cycle. 

**Observation:** A given flow _f_ in the network has minimum cost in the network _G_ if there are no negative cost cycles in the residual network _Gr_.

**Observation:** The shortest path from `start` to `end` in the graph _G_ doesn't introduce any negative cycles in the corresponding residual graph _Gr_.

This is true, because in the residual graph, the negative cost of going from `end` to `start` along the shortest path is less than the positive cost of going from `start` to `end` along any of the remaining paths.

**Observation:** A minimum cost flow of any given amount (less than the overall max-flow of the network) can be obtained iteratively as follows:

	1. hjasdf
	2. 



## Acknowledgements

We are grateful to the entire team behind School 42 and its [Moscow branch](https://21-school.ru
), as well as to my fellow students for help and support. Some ideas for tests found in `example-maps` are borrowed from a [similar project](https://github.com/davhojt/lem_in) by [davhojt](https://github.com/davhojt).

---
If you have any questions, please contact me on Github.
