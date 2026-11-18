#pragma once
#include <string>

const int EVT_VISIT = 0;
const int EVT_COMPARE = 1;
const int EVT_INSERT = 2;
const int EVT_UNLINK = 3;
const int EVT_SWAP_VALUE = 4;
const int EVT_ROTATE = 5;
const int EVT_UPDATE_HEIGHT = 6;
const int EVT_UPDATE_SIZE = 7;
const int EVT_BALANCE_ALERT = 8;
const int EVT_HIGHLIGHT_SUBTREE = 9;
const int EVT_HEAP_BUILD = 10;
const int EVT_HEAP_SWAP = 11;
const int EVT_HEAPIFY_START = 12;   
const int EVT_HEAPIFY_DONE = 13;
const int EVT_EXTRACT_MAX = 14;
const int EVT_MARK_SORTED = 15;
const int EVT_HEAP_SIZE_CHANGE = 16;
const int EVT_HEAP_SORT_COMPLETE = 17;
const int EVT_DONE = 18;

const int ROT_LL = 0;
const int ROT_RR = 1;
const int ROT_LR = 2;
const int ROT_RL = 3;

const int SIDE_LEFT = 0;
const int SIDE_RIGHT = 1;

const int HL_VISITED = 0;
const int HL_SKIPPED = 1;
const int HL_RESULT = 2;

inline const char* eventTypeName(int t) {
    switch (t) {
    case EVT_VISIT:              return "VISIT";
    case EVT_COMPARE:            return "COMPARE";
    case EVT_INSERT:             return "INSERT";
    case EVT_UNLINK:             return "UNLINK";
    case EVT_SWAP_VALUE:         return "SWAP_VALUE";
    case EVT_ROTATE:             return "ROTATE";
    case EVT_UPDATE_HEIGHT:      return "UPDATE_HEIGHT";
    case EVT_UPDATE_SIZE:        return "UPDATE_SIZE";
    case EVT_BALANCE_ALERT:      return "BALANCE_ALERT";
    case EVT_HIGHLIGHT_SUBTREE:  return "HIGHLIGHT_SUBTREE";
    case EVT_HEAP_BUILD:         return "HEAP_BUILD";
    case EVT_HEAP_SWAP:          return "HEAP_SWAP";
    case EVT_HEAPIFY_START:      return "HEAPIFY_START";
    case EVT_HEAPIFY_DONE:       return "HEAPIFY_DONE";
    case EVT_EXTRACT_MAX:        return "EXTRACT_MAX";
    case EVT_MARK_SORTED:        return "MARK_SORTED";
    case EVT_HEAP_SIZE_CHANGE:   return "HEAP_SIZE_CHANGE";
    case EVT_HEAP_SORT_COMPLETE: return "HEAP_SORT_COMPLETE";
    case EVT_DONE:               return "DONE";
    }
    return "UNKNOWN";
}

struct Event {
    int type;           
    int nodeA;
    int nodeB;
    int oldVal;
    int newVal;
    int aux;            
    std::string note;

    Event()
        : type(EVT_DONE), nodeA(-1), nodeB(-1),
        oldVal(0), newVal(0), aux(0), note() {
    }

    Event(int t, int a = -1, int b = -1,
        int oldV = 0, int newV = 0, int auxV = 0,
        const std::string& n = "")
        : type(t), nodeA(a), nodeB(b),
        oldVal(oldV), newVal(newV), aux(auxV), note(n) {
    }
};