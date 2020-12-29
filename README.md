# CPP-Real-time.multithreaded-system-projects

## Lab 0
This lab was just a simple refresher on OOP and C++ using Visual Studios 2017

## Lab 1
This lab demonstrates object-oriented design via different classes that interact with each other.
The purpose of this lab was to become familiar with C++ objects, classes, inheritance and header files.

## Lab 2
The purpose of this lab was to learn about the concepts of concurrency
by making a simple application that has several programs/processes running at the same time. In this lab (and the rest of these labs as well) there are usages from a library called RT which was created by Paul Davies of the UBC ECE Department. 
In this lab there are thread and process usages, these threads and processes are created via making calls to the kernel of the OS.

## Lab 3
This lab continues where lab 2 left off by diving further into multi-threading. In this lab, we implement a simple Car class, which has a main thread which can accelerate, stop and cruise the car, and a second thread which outputs the value of the speedometer every few seconds.


## Lab 4
In this lab, we answer the question "How can 2 different threads/processes communicate?". We answer this question by using Pipelines and Datapools, these pipelines and Datapools allow threads to communicate with each other via a shared resource. We ask the kernel to set aside a piece of memory that will be shared between processes.

## Lab 5
In this lab, we tackle the problem of thread synchronisation and mutual exclusion, and why they are so important in multi-threaded systems. We can solve these problems by using mutexes and semaphores. 

## Lab 6

For the final lab, we tie together everything learned, and create a multi-threaded race car simulation. This lab utilizes threads/processes, mutexes, semaphores, and all the other goodies needed for an excellent concurrent system.
