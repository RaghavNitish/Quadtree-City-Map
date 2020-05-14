#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <string>
#include "header.h"

//Constructor for QuadTreeNode class 
QuadTreeNode::QuadTreeNode(std::string &p_name, float &p_x, float &p_y, unsigned int &p_population, unsigned int &p_col, unsigned int &p_salary){
    name = p_name;
    x = p_x;
    y = p_y;
    population = p_population;
    col = p_col;
    salary = p_salary;

    NW = NULL;
    NE = NULL;
    SW = NULL;
    SE = NULL;
}

bool QuadTreeNode::insert_node(std::string &p_name, float &p_x, float &p_y, unsigned int &p_population, unsigned int &p_col, unsigned int &p_salary){
    if (x == p_x && y == p_y){
        std::cout << "failure" << std::endl;
        return false;
    }
    if (p_x >= x && p_y > y){
        //Node is placed in the NE direction
        if (NE == NULL){
            NE = new QuadTreeNode(p_name, p_x, p_y, p_population, p_col, p_salary);
            std::cout << "success" << std::endl;
            return true;
        }
        else{
            return NE->insert_node(p_name, p_x, p_y, p_population, p_col, p_salary);
        }
    }
    if (p_x < x && p_y >= y){
        //Node is placed in the NW direction
        if (NW == NULL){
            NW = new QuadTreeNode(p_name, p_x, p_y, p_population, p_col, p_salary);
            std::cout << "success" << std::endl;
            return true;
        }
        else{
            return NW->insert_node(p_name, p_x, p_y, p_population, p_col, p_salary);
        }
    }
    if (p_x <= x && p_y < y){
        //Node is placed in the SW direction
        if (SW == NULL){
            SW = new QuadTreeNode(p_name, p_x, p_y, p_population, p_col, p_salary);
            std::cout << "success" << std::endl;
            return true;
        }
        else{
            return SW->insert_node(p_name, p_x, p_y, p_population, p_col, p_salary);
        }
    }
    if (p_x > x && p_y <= y){
        //Node is placed in the SE direction
        if (SE == NULL){
            SE = new QuadTreeNode(p_name, p_x, p_y, p_population, p_col, p_salary);
            std::cout << "success" << std::endl;
            return true;
        }
        else{
            return SE->insert_node(p_name, p_x, p_y, p_population, p_col, p_salary);
        }
    }
}

bool QuadTreeNode::search_node(float &p_x, float &p_y){
    if (x == p_x && y == p_y){
        std::cout << "found " << name << std::endl;
        return true;
    }
    if (p_x >= x && p_y > y){
        //NE direction
        if (NE == NULL){
            std::cout << "not found" << std::endl;
            return false;
        }
        else{
            return NE->search_node(p_x, p_y);
        }
    }
    if (p_x < x && p_y >= y){
        //NW direction
        if (NW == NULL){
            std::cout << "not found" << std::endl;
            return false;
        }
        else{
            return NW->search_node(p_x, p_y);
        }
    }
    if (p_x <= x && p_y < y){
        //SW direction
        if (SW == NULL){
            std::cout << "not found" << std::endl;
            return false;
        }
        else{
            return SW->search_node(p_x, p_y);
        }
    }
    if (p_x > x && p_y <= y){
        //SE direction
        if (SE == NULL){
            std::cout << "not found" << std::endl;
            return false;
        }
        else{
            return SE->search_node(p_x, p_y);
        }
    }
}

unsigned int QuadTreeNode::max_node_1(QuadTreeNode* p_node, std::string &p_attr){
    unsigned int max_1 = 0;
    unsigned int max_2 = 0;
    unsigned int max_3 = 0;
    unsigned int max_4 = 0;

    if (p_node->NE == NULL){
        max_1 = 0;
    }
    else{
        max_1 = max_node_1(p_node->NE, p_attr);
    }
    //-----------------------------------------------------
    if (p_node->NW == NULL){
        max_2 = 0;
    }
    else{
        max_2 = max_node_1(p_node->NW, p_attr);
    }
    //-----------------------------------------------------
    if (p_node->SE == NULL){
        max_3 = 0;
    }
    else{
        max_3 = max_node_1(p_node->SE, p_attr);
    }
    //------------------------------------------------------
    if (p_node->SW == NULL){
        max_4 = 0;
    }
    else{
        max_4 = max_node_1(p_node->SW, p_attr);
    }
    
    if (p_attr == "p"){
        return std::max({max_1, max_2, max_3, max_4, p_node->population});
    }
    else if (p_attr == "r"){
        return std::max({max_1, max_2, max_3, max_4, p_node->col});
    }
    else if (p_attr == "s"){
        return std::max({max_1, max_2, max_3, max_4, p_node->salary});
    }
}

bool QuadTreeNode::max_node(float &p_x, float &p_y, std::string &p_dir, std::string &p_attr){
    QuadTreeNode* temp;

   if (x == p_x && y == p_y){
       if (p_dir == "NE"){
           temp = NE;
       }
       if (p_dir == "NW"){
           temp = NW;
       }
        if (p_dir == "SW"){
           temp = SW;
       }
        if (p_dir == "SE"){
           temp = SE;
       }

       if (temp == NULL){
           std::cout << "failure" << std::endl;
           return false;
       }

       unsigned int max_attribute = 0;
       max_attribute = max_node_1(temp, p_attr);

       std::cout << "max " << max_attribute << std::endl;

    return true;
    }

    if (p_x >= x && p_y > y){
        //NE direction
        if (NE == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return NE->max_node(p_x, p_y, p_dir, p_attr);
        }
    }
    if (p_x < x && p_y >= y){
        //NW direction
        if (NW == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return NW->max_node(p_x, p_y, p_dir, p_attr);
        }
    }
    if (p_x <= x && p_y < y){
        //SW direction
        if (SW == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return SW->max_node(p_x, p_y, p_dir, p_attr);
        }
    }
    if (p_x > x && p_y <= y){
        //SE direction
        if (SE == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return SE->max_node(p_x, p_y, p_dir, p_attr);
        }
    }
}

unsigned int QuadTreeNode::min_node_1(QuadTreeNode* p_node, std::string &p_attr){
    unsigned int min_1 = 4294967295 ;
    unsigned int min_2 = 4294967295 ;
    unsigned int min_3 = 4294967295 ;
    unsigned int min_4 = 4294967295 ;

    if (p_node->NE == NULL){
        min_1 = 4294967295;
    }
    else{
        min_1 = min_node_1(p_node->NE, p_attr);
    }
    //-----------------------------------------------------
    if (p_node->NW == NULL){
        min_2 = 4294967295 ;
    }
    else{
        min_2 = min_node_1(p_node->NW, p_attr);
    }
    //-----------------------------------------------------
    if (p_node->SE == NULL){
        min_3 = 4294967295 ;
    }
    else{
        min_3 = min_node_1(p_node->SE, p_attr);
    }
    //------------------------------------------------------
    if (p_node->SW == NULL){
        min_4 = 4294967295 ;
    }
    else{
        min_4 = min_node_1(p_node->SW, p_attr);
    }
    
    if (p_attr == "p"){
        return std::min({min_1, min_2, min_3, min_4, p_node->population});
    }
    else if (p_attr == "r"){
        return std::min({min_1, min_2, min_3, min_4, p_node->col});
    }
    else if (p_attr == "s"){
        return std::min({min_1, min_2, min_3, min_4, p_node->salary});
    }
}

bool QuadTreeNode::min_node(float &p_x, float &p_y, std::string &p_dir, std::string &p_attr){
    QuadTreeNode* temp;

    if (x == p_x && y == p_y){
       if (p_dir == "NE"){
           temp = NE;
       }
       if (p_dir == "NW"){
           temp = NW;
       }
        if (p_dir == "SW"){
           temp = SW;
       }
        if (p_dir == "SE"){
           temp = SE;
       }

       if (temp == NULL){
           std::cout << "failure" << std::endl;
           return false;
       }

       unsigned int min_attribute = 0;
       min_attribute = min_node_1(temp, p_attr);

        std::cout << "min " << min_attribute << std::endl;

    return true;
    }

    if (p_x >= x && p_y > y){
        //NE direction
        if (NE == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return NE->min_node(p_x, p_y, p_dir, p_attr);
        }
    }
    if (p_x < x && p_y >= y){
        //NW direction
        if (NW == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return NW->min_node(p_x, p_y, p_dir, p_attr);
        }
    }
    if (p_x <= x && p_y < y){
        //SW direction
        if (SW == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return SW->min_node(p_x, p_y, p_dir, p_attr);
        }
    }
    if (p_x > x && p_y <= y){
        //SE direction
        if (SE == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return SE->min_node(p_x, p_y, p_dir, p_attr);
        }
    }
}

unsigned int QuadTreeNode::total_node_1(QuadTreeNode* p_node, std::string &p_attr){
    unsigned int total_1 = 0 ;
    unsigned int total_2 = 0 ;
    unsigned int total_3 = 0 ;
    unsigned int total_4 = 0 ;

    if (p_node->NE == NULL){
        total_1 = 0;
    }
    else{
        total_1 = total_node_1(p_node->NE, p_attr);
    }
    //-----------------------------------------------------
    if (p_node->NW == NULL){
        total_2 = 0;
    }
    else{
        total_2 = total_node_1(p_node->NW, p_attr);
    }
    //-----------------------------------------------------
    if (p_node->SE == NULL){
        total_3 = 0 ;
    }
    else{
        total_3 = total_node_1(p_node->SE, p_attr);
    }
    //------------------------------------------------------
    if (p_node->SW == NULL){
        total_4 = 0 ;
    }
    else{
        total_4 = total_node_1(p_node->SW, p_attr);
    }
    
    if (p_attr == "p"){
        return total_1 + total_2 + total_3 + total_4 + p_node->population;
    }
    else if (p_attr == "r"){
        return total_1 + total_2 + total_3 + total_4 + p_node->col;
    }
    else if (p_attr == "s"){
        return total_1 + total_2 + total_3 + total_4 + p_node->salary;
    }
}

bool QuadTreeNode::total_node(float &p_x, float &p_y, std::string &p_dir, std::string &p_attr){
    QuadTreeNode* temp;

    if (x == p_x && y == p_y){
       if (p_dir == "NE"){
           temp = NE;
       }
       if (p_dir == "NW"){
           temp = NW;
       }
        if (p_dir == "SW"){
           temp = SW;
       }
        if (p_dir == "SE"){
           temp = SE;
       }

       if (temp == NULL){
           std::cout << "failure" << std::endl;
           return false;
       }

       unsigned int total_attribute = 0;
       total_attribute = total_node_1(temp, p_attr);

        std::cout << "total " << total_attribute << std::endl;

    return true;
    }

    if (p_x >= x && p_y > y){
        //NE direction
        if (NE == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return NE->total_node(p_x, p_y, p_dir, p_attr);
        }
    }
    if (p_x < x && p_y >= y){
        //NW direction
        if (NW == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return NW->total_node(p_x, p_y, p_dir, p_attr);
        }
    }
    if (p_x <= x && p_y < y){
        //SW direction
        if (SW == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return SW->total_node(p_x, p_y, p_dir, p_attr);
        }
    }
    if (p_x > x && p_y <= y){
        //SE direction
        if (SE == NULL){
            std::cout << "failure" << std::endl;
            return false;
        }
        else{
            return SE->total_node(p_x, p_y, p_dir, p_attr);
        }
    }
}

void QuadTreeNode::node_clear(){
    if (NE != NULL){
        NE->node_clear();
        delete NE;
        NE = NULL;
    }
    if (NW != NULL){
        NW->node_clear();
        delete NW;
        NW = NULL;
    }
    if (SE != NULL){
        SE->node_clear();
        delete SE;
        SE = NULL;
    }
    if (SW != NULL){
        SW->node_clear();
        delete SW;
        SW = NULL;
    }
}

QuadTree::QuadTree(){
    root = NULL;
    count=0;
}

void QuadTree::insert(std::string &p_name, float &p_x, float &p_y, unsigned int &p_population, unsigned int &p_col, unsigned int &p_salary){
    //If root is NULL...
    if (root == NULL){
        root = new QuadTreeNode(p_name, p_x, p_y, p_population, p_col, p_salary); 
        std::cout << "success" << std::endl;
        count++;
    }
    else{
        bool x = root->insert_node(p_name, p_x, p_y, p_population, p_col, p_salary);
        if (x){
            count++;
        }
    }
}

void QuadTree::search(float &p_x, float &p_y){
    //If root is NULL...
    if (root == NULL){
        std::cout << "not found" << std::endl;
    }
    else{
        bool x = root->search_node(p_x, p_y);
    }
}

void QuadTree::q_max(float &p_x, float &p_y, std::string &p_dir, std::string &p_attr){
    //If root is NULL...
    if (root == NULL){
        std::cout << "failure" << std::endl;
    }
    else{
        bool x = root->max_node(p_x, p_y, p_dir, p_attr);
    }
}

void QuadTree::q_min(float &p_x, float &p_y, std::string &p_dir, std::string &p_attr){
    //If root is NULL...
    if (root == NULL){
        std::cout << "failure" << std::endl;
    }
    else{
        bool x = root->min_node(p_x, p_y, p_dir, p_attr);
    }
}

void QuadTree::q_total(float &p_x, float &p_y, std::string &p_dir, std::string &p_attr){
    //If root is NULL...
    if (root == NULL){
        std::cout << "failure" << std::endl;
    }
    else{
        bool x = root->total_node(p_x, p_y, p_dir, p_attr);
    }

}

void QuadTree::print_node(QuadTreeNode* p_node){
    if (p_node != NULL){
        print_node(p_node->NE);
        print_node(p_node->NW);
        std::cout << p_node->name << " ";
        print_node(p_node->SW);
        print_node(p_node->SE);
    }
}

void QuadTree::print(){
    //If root is not NULL...
    if (root != NULL){
        print_node(root);
        std::cout << std::endl;
    }
}

void QuadTree::clear(){
    if (root != NULL){
        root->node_clear();
        delete root;
        root = NULL;
        count = 0;
    }
    std::cout << "success" << std::endl;
}
void QuadTree::size(){
    std::cout << "tree size " << count << std::endl;
}

QuadTree::~QuadTree(){
    if (root != NULL){
        root->node_clear();
        delete root;
        root = NULL;
        count = 0;
    }
}