# Lem_in

*This project is part of the official curriculum at [School 42](https://en.wikipedia.org/wiki/42_(school)).*

# Overview

* [Official instructions](docs/lem-in.en.pdf)
* [Code documentation](https://almayor.github.io/Lem-in)
* This project practices the following algorithmic topics
	* path search in undirected graphs
	* maxflow / mincut
	* sorts
	* efficient data representation (graphs, arrays, queues)
* This project is written in compliance with the [Norm](docs/subjects/norme.en.pdf)

# Run

To compile, run

```sh
git clone https://github.com/almayor/Lem-in
cd Lem-in
git submodule --init --recursive
make
```
Then try some example maps

```sh
./Lem_in < example-maps/flow-thousand.txt
```
or generate your own

```sh
./generator --flow-thousand | ./Lem_in
```

(_NOTE_ that the `generator` has been made available to use in a Linux compilation. If you're running OSX, you could use a Docker `gcc` container or a VM. Alternatively, you could use the many pre-generated example maps in the `example-maps` directory)

# Acknowledgements

We are grateful to the entire team behind School 42 and its [Moscow branch](https://21-school.ru
), as well as to my fellow students for help and support. Some ideas for tests found in `example-maps` are borrowed from a [similar project](https://github.com/davhojt/lem_in) by [davhojt](https://github.com/davhojt).

---
If you have any questions, please contact me on Github.
