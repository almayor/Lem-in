# lem-in

*This project is part of the official curriculum at [School 42](https://en.wikipedia.org/wiki/42_(school)).*

## Disclaimer

> At [School 42](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written to comply with a coding standard (also known as the "[Norm](./docs/subjects/norme.en.pdf)"). As a result, the implementation of certain parts may appear strange.

## Overview

* [Official instructions](docs/subjects/lem-in.en.pdf)
* [Code documentation](https://almayor.github.io/lem-in)
* [Algorithm explanation](docs/algorithm-explanation.pdf)
* This project practices the following algorithmic topics
	* minimum cost maximum flow (Ford-Fulkerson, Suurballe)
	* path search in directed graphs (BFS, Dijkstra, Bellman-Ford)
	* sorts (quick sort, insertion sort)
	* efficient data representation (priority queues, graphs, arrays, queues, linked lists)

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

I have written a detailed [PDF](docs/algorithm-explanation.pdf) to outline my thought process when designing the algorithm. Please have a look if you're interested.

## Useful links

1.  <https://courses.csail.mit.edu/6.854/06/scribe/s12-minCostFlowAlg. pdf>
2. <http://www.macfreek.nl/memory/Disjoint_Path_Finding>
3. <https://en.wikipedia.org/wiki/Suurballe%27s_algorithm>


## Acknowledgements

We are grateful to the entire team behind School 42 and its [Moscow branch](https://21-school.ru
), as well as to my fellow students for help and support. Some ideas for tests found in `example-maps` are borrowed from a [similar project](https://github.com/davhojt/lem_in) by [davhojt](https://github.com/davhojt).

---
If you have any questions, please contact me on Github.
