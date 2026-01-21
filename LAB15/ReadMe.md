# Lab 15: Graph Algorithms (Adjacency Matrix & List)

## Assignment Details

**Course code and title:** CMP-210 | Data Structures and Algorithms  
**Lab:** 15  
**Instructor:** Dr Salman Naseer  
**Date:** 2026-01-20  
**Class:** BS (CS & IT)  
**Semester:** 4th  
**Total Marks:** 10  

---

## Question 1
Write a program to make an undetected graph using adjacency matrix and adjacency list and apply all codes for the following problems:

* Graph Traversal (BFS & DFS)
* Topological Sort
* Spanning Tree
* Minimum Spanning Tree (Prim's Algorithm)
* Shortest Path (Dijkstra's Algorithm)

## Question 2
Write a program to store the divisions of Punjab as nodes in your weighted graph, calculate the distance between the divisions by using Google map. Apply the Dijkstra Algorithm to find the shortest distance between any two nodes.

---

## Project Structure

This project contains the solution for the above questions using C++.

* **`Mgraph.h`**: Implementation of the Graph using an **Adjacency Matrix**. Handles both Directed and Undirected graphs.
* **`Lgraph.h`**: Implementation of the Graph using an **Adjacency List**. Optimized for sparse graphs.
* **`main.cpp`**: 
    * Demonstrates Q1 by running BFS, DFS, MST, and Topological Sort on sample graphs.
    * Solves Q2 by creating a graph of Punjab divisions (Lahore, Multan, Rawalpindi, etc.) with real-world distances and calculating the shortest path.

## How to Run

1.  Ensure you have a C++ compiler (like g++).
2.  Compile the main file:
    ```bash
    g++ main.cpp -o lab15
    ```
3.  Run the executable:
    ```bash
    ./lab15
    ```
