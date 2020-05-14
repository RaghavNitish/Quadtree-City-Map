#include <iostream>
#include <string>

//This class represents the individual nodes in the Quad Tree data structure implementation
class QuadTreeNode{
    public:
        //4 pointers
        QuadTreeNode* NW;
        QuadTreeNode* NE;
        QuadTreeNode* SW;
        QuadTreeNode* SE;

        //Data Aspect
        std::string name;
        unsigned int population;
        unsigned int col;
        unsigned int salary;
        float x;
        float y;

        //functions
        QuadTreeNode(std::string &, float &, float &, unsigned int &, unsigned int &, unsigned int &);
        bool insert_node(std::string &, float &, float &, unsigned int &, unsigned int &, unsigned int &);
        bool search_node(float &, float &);
        bool max_node(float &, float &, std::string &, std::string &);
        bool min_node(float &, float &, std::string &, std::string &);
        bool total_node(float &, float &, std::string &, std::string &);
        void node_clear();
        unsigned int max_node_1(QuadTreeNode*, std::string &);
        unsigned int min_node_1(QuadTreeNode*, std::string &);
        unsigned int total_node_1(QuadTreeNode*, std::string &);
};

//This class represents the overall Quad Tree in the Quad Tree data structure implementation
class QuadTree{
    public:
        QuadTreeNode* root;
        unsigned int count;

        QuadTree();
        ~QuadTree();
        void insert(std::string &, float &, float &, unsigned int &, unsigned int &, unsigned int &);
        void search(float &, float &);
        void q_max(float &, float &, std::string &, std::string &);
        void q_min(float &, float &, std::string &, std::string &);
        void q_total(float &, float &, std::string &, std::string &);
        void print();
        void clear();
        void size();
        void print_node(QuadTreeNode*);
};