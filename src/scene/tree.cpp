#include "tree.hpp"

vector<Object *> Tree::data;
vector<Object *> Tree::to_destroy;
int Tree::new_id = 0;

void Tree::toDestroy()
{
    for (int i = 0; i < to_destroy.size(); i++)
    {
        Object * obj = to_destroy[i];
        if (new_id <= 0)
            return;
        int index = obj->getObjectId();

        int last_index = data.size() - 1;

        Object *temp_ptr = data[last_index];
        data[last_index] = data[index];
        data[index] = temp_ptr;

        data[index]->setObjectId(index);

        Object *to_destroy = data[last_index];
        data.pop_back();
        delete to_destroy;

        new_id--;
    }
    to_destroy.clear();
}

int Tree::size()
{
    return new_id;
}

void Tree::iterate()
{
    for (int i = 0; i < data.size(); i++)
    {
        data[i]->update();
    }
}

void Tree::iterateDraw()
{
    for (int i = 0; i < data.size(); i++)
    {
        data[i]->draw();
    }
    toDestroy();
    
}

void Tree::instantiate(Object *obj)
{
    data.push_back(obj);
    obj->setObjectId(new_id);
    new_id++;
}

void Tree::destroy(Object *obj)
{
    to_destroy.push_back(obj);
}
