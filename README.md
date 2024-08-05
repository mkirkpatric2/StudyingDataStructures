# StudyingDataStructures

This repo will contain C files I write as I study C & data structures and algorithms. I hope to track my personal development in both writing C and understanding these topics. The intent is that as I learn more--as I play more--this repo will fill itself out and demonstrate my growth.     
         
At the moment, as I learn different concepts, I find a way to include them in "/game/"    
    
 

## Linked Lists/

#### 1_LinkedList.c

This file shows the result of my first time working through (a) understanding the basics of a linked list, and (b) how to write one and navigate through one. 

#### 2_TwoWayLinkedList.c

This file merely adds (a) two way movement through the linked list implementation found in 1_LinkedList.c and (b) one function relying on said addition. 

#### 3_SimpleCircularLinkedList.c

This file contains a simple implementation of a circular linked list. Besides list-entry creation, it includes one function to print data within entries in LIFO order and loops if the requested quantity exceeds the number of entries. 

#### 4_TwoWayCircularFixedQuantity.c

My goal was to create a fixed-quantity circular linked list. My intent is to port this to /game/ as a save-state management method. In each entry, I'll include compressed data reflecting game-state changes [method tbd]. Each turn, an entry will be updated and the marker moved around the circle. After reaching the desired number, 10 for this exercise, subsequent entries will override the next entry in the list. 

As each entry will reflect a "turn," the goal is for the data to enable backwards replay. Upon reaching a fail-state, the player will have an option to "rewind" upon which the state will revert by undoing the actions contianed in the data on each entry [down the road: including visual represnetation of each rewound turn]. 

## Hash Maps/

## Algorithms/

### binarySearch.h

My first attempt at writing a binary search function. After finishing it, I added a version for sorting the opposite direction. 

Sorts arrays of integers.


### selectionSort.h

My first attempt at writing a selection sort function. 

Sorts arrays of integers from low to high.


### quickSort.h 

My first attempt at writing a quicksort algorithm without looking for help was pretty close, but I made new arrays after every sort around a pivot. As a result, I struggled to put them all back together [sic - I failed to] and the function was memory inefficient. 

After ~6 hours of trying [including busting out the ol' colored blocks to physically mock the sorting logic], I searched for an implementation to breakdown and understand. My primary mistake was not sending the same array with truncated indeces back into the function after each sort. Ultimately, the version here is fundamentally similar to the version I found upon searching. 

Besides some syntactical edits, I did add the option for low->high and high->low sorting. 

Future: I intend to add an alphabetical sorting version. I intend to port some version to /game/ as a method to sort the yet-implemented inventory. 




## /game/


