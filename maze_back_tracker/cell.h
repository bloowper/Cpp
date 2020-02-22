//
// Created by gtato on 08.02.2020.
//

#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H
/*in use::
 * concept of Encapsulation
 *
 */

class cell {


public:
    cell* left;
    cell* right;
    cell* top;
    cell* bottom;

    int w;
    int k;

    bool isPath;
    bool visited;

    bool is_start;
    bool is_end;

    bool isleft;
    bool isright;
    bool istop;
    bool isbottom;

    void set_left(cell& acell);
    void set_right(cell& acell);
    void set_top(cell& acell);
    void set_bottom(cell& acell);

    cell();
    cell(int w, int k);
    cell& operator=(const cell& second);

    bool is_left_available();
    bool is_right_available();
    bool is_top_available();
    bool is_bottom_available();


    void set_as_main_path();
    void set_as_visited();
    bool get_is_main_path();
    bool get_was_visited();


    bool was_wisited();




};


#endif //UNTITLED_CELL_H
