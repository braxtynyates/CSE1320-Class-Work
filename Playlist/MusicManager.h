#ifndef MusicManger_h
#define MusicManger_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct duration
{
    int mins;
    int secs;
}Duration;

typedef struct record
{
    char artist[100];
    char album[100];
    char title[100];
    char genre[100];

    Duration duration;
    int timesPlayed;
    int rating;
}Record;

typedef struct node
{
    Record* data;
    struct node* next;
    struct node* previous;
}Node;

void insertFront(Node **pList, Node *newNode);

void clear_stdin(void);

void testToSeeIfInt(int *invalidInt);

void loadFromFile(Node **pList);

void store(Node **pList);

void display (Node *pList);

void displayByArtist(Node *pList);

void newRecord(Node **pList);

void deleteRecord(Node **pList);

void editRecord(Node **pList);

void sortRecord();

void rate(Node **pList);

void playSongs(Node **pList);

void shuffle();

void exitProgram(Node **pList);

#endif