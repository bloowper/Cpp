//
// Created by gtato on 08.02.2020.
//

#include "cell.h"
#include <cstddef>

cell::cell() {
    bottom = nullptr;
    top = nullptr;
    right = nullptr;
    left = nullptr;
    isPath = false;
    visited = false;
    is_start = false;
    is_end = false;
}

cell::cell(int w, int k)
{
    this->w = w;
    this->k = k;
    bottom = nullptr;
    top = nullptr;
    right = nullptr;
    left = nullptr;
    isPath = false;
    visited = false;
    is_start = false;
    is_end = false;


    isleft = false;
    isright = false;
    istop = false;
    isbottom = false;
}

cell& cell::operator=(const cell& second)
{
    this->w = second.w;
    this->k = second.k;
    bottom = second.bottom;
    top = second.top;
    right = second.top;
    left = second.left;
    isPath = second.isPath;
    visited = second.visited;
    is_start = second.is_start;
    is_end = second.is_end;
    return *this;
}


//set connection
void cell::set_left(cell& acell)
{
    this->isleft = true;
    this->left = &acell;

    acell.isright = true;
    acell.right = this;
}

void cell::set_right(cell& acell)
{
    this->right = &acell;
    this->isright = true;

    acell.isleft = true;
    acell.left = this;
}

void cell::set_top(cell& acell)
{
    this->istop = true;
    this->top = &acell;
    acell.isbottom = true;
    acell.bottom = this;
}

void cell::set_bottom(cell& acell)
{
    this->bottom = &acell;
    this->isbottom = true;
    acell.top = this;
    acell.istop = true;
}
//////////////////////


//IS AVAILABLE
bool cell::is_left_available() {
    if (left == nullptr)
        return false;
    else
        return true;
}

bool cell::is_right_available() {
    if (right == nullptr)
        return false;
    else
        return true;
}

bool cell::is_top_available() {
    if (top == nullptr)
        return false;
    else
        return true;
}

bool cell::is_bottom_available() {
    if (bottom == nullptr)
        return false;
    else
        return true;
}
////////



//path method
bool cell::get_is_main_path()
{
    return this->isPath;
}

bool cell::get_was_visited()
{
    return this->visited;
}

//path set methods
void cell::set_as_main_path()
{
    isPath = true;
}

void cell::set_as_visited()
{

    visited = true;
}




bool cell::was_wisited()
{
    if (visited == true)
        return false;
    else
    {
        return true;
    }
}




