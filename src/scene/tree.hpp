#pragma once
#include "object.hpp"
#include <vector>

using namespace std;

class Tree
{

private:
    static int new_id;

    static vector<Object*> to_destroy;
    static vector<Object*> data;

    static void toDestroy();

public:
    static int size();
    static void iterate();
    static void iterateDraw();
    static void instantiate(Object * obj);
    static void destroy(Object * obj);
};