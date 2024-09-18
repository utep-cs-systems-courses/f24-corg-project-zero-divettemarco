// Divette Marco | 2024-09-17
#include <stdio.h>
#include "draw.h"

/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

// Prints an arrow of specified height whose left col is at leftCol.
void print_arrow(int leftCol, int size)
{
  int endCol = leftCol + size;
  int pointCol = endCol-3;
  for (int row = 0; row <= 4; row++) {
    int col;
    switch (row){
    // to create the top and bottom tips of the arrow point.
    case 0: case 4:
      for (col = 0; col < endCol; col++){
	if (col == pointCol){
	    putchar('*');    
	}
	else{
	  putchar(' ');
	}
      }
      putchar('\n');
      break;
    // to continue to create the top and bottom tips of the arrow point.
    case 1: case 3:
      for (col = 0; col < pointCol; col++) putchar(' ');
      for (       ; col < endCol-1;  col++) putchar('*');
      putchar(' ');
      putchar('\n');
      break;
    // to create the arrow line and create arrow point.
    case 2:
      for (col = 0; col < leftCol; col++) putchar(' ');
      for (       ; col < endCol;  col++) putchar('*');
      putchar('\n');
      break;
    default:      
      printf("unrecognized option '%row', please try again!", row);
    }
  }
}
