# towerOfHanoi
#### by Carlos Flores & George Navarro

Design and analyze an algorithm for solving a variant of the Tower of Hanoi in C++.

![Image of demo](https://media.giphy.com/media/S5c0DMd1KDqK6wrA8V/giphy.gif)

Given a directed graph (V,E) of Vectors {Start, Aux1, Aux2, Aux3, Dest} and Edges {(Start, Aux1),(Aux1, Aux2),(Aux2, Aux3),(Aux3, Dest),(Aux3, Aux1)} design an algorithm to successfully move a stack of N discs from the Start peg to the Dest peg.  

![Image of graph](https://github.com/cflores713/towerOfHanoi/blob/master/tizkGraph.png)

The traditional rules for the Tower of Hanoi still stand: Each disc has a diameter that is larger than the discs above it on the stack. You can only move one disc at a time, you can only move a smaller disc onto a stack with larger discs. and you can only move discs by using edges in the directed graph.


![Image of math](https://github.com/cflores713/towerOfHanoi/blob/master/complexity.png)
More details can be found in the Analysis Report that is the pdf file included in this repository.
