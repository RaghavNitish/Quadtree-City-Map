#include <iostream>
#include "header.h"
#include <string>

int main(){

	std::string line;
	QuadTree quadtree;


	while(getline(std::cin, line)){
        if (line.substr(0, 1) == "i"){
            int pos = (line.substr(2)).find(";");
            std::string name = line.substr(2, pos);

            std::string line1 = line.substr(pos+3);
            pos = line1.find(";");
            float x = std::stof(line1.substr(0, pos));

            line1 = line1.substr(pos+1);
            pos = line1.find(";");
            float y = std::stof(line1.substr(0, pos));

            line1 = line1.substr(pos+1);
            pos = line1.find(";");
            unsigned int population = std::stoi(line1.substr(0, pos));

            line1 = line1.substr(pos+1);
            pos = line1.find(";");
            unsigned int col = std::stof(line1.substr(0, pos));

            line1 = line1.substr(pos+1);
            pos = line1.find(";");
            unsigned int salary = std::stoi(line1.substr(0, pos));

            quadtree.insert(name, x, y, population, col, salary);
        }

        else if (line.substr(0, 2) == "s "){
            int pos = line.find(";");
            float x = std::stof(line.substr(2, pos));

            float y = std::stof(line.substr(pos+1));

            quadtree.search(x, y);
        }
        else if (line.substr(0, 5) == "q_max"){
            int pos = (line.substr(5)).find(";");
            float x = std::stof(line.substr(5, pos));

            std::string line1 = line.substr(pos+6);
            pos = line1.find(";");
            float y = std::stof(line1.substr(0, pos));

            line1 = line1.substr(pos+1);
            pos = line1.find(";");
            std::string dir = line1.substr(0, pos);

            line1 = line1.substr(pos+1);
            pos = line1.find(";");
            std::string attr = line1.substr(0, pos);

            quadtree.q_max(x, y, dir, attr);

        }
        else if (line.substr(0, 5) == "q_min"){
            int pos = (line.substr(5)).find(";");
            float x = std::stof(line.substr(5, pos));

            std::string line1 = line.substr(pos+6);
            pos = line1.find(";");
            float y = std::stof(line1.substr(0, pos));

            line1 = line1.substr(pos+1);
            pos = line1.find(";");
            std::string dir = line1.substr(0, pos);

            line1 = line1.substr(pos+1);
            pos = line1.find(";");
            std::string attr = line1.substr(0, pos);

            quadtree.q_min(x, y, dir, attr);
        }
        else if (line.substr(0, 7) == "q_total"){
            int pos = (line.substr(7)).find(";");
            float x = std::stof(line.substr(7, pos));

            std::string line1 = line.substr(pos+8);
            pos = line1.find(";");
            float y = std::stof(line1.substr(0, pos));

            line1 = line1.substr(pos+1);
            pos = line1.find(";");
            std::string dir = line1.substr(0, pos);

            line1 = line1.substr(pos+1);
            pos = line1.find(";");
            std::string attr = line1.substr(0, pos);

            quadtree.q_total(x, y, dir, attr);
        }

        else if (line.substr(0, 5) == "print"){
            quadtree.print();
        }
        else if (line.substr(0, 5) == "clear"){
            quadtree.clear();
        }
        else if (line.substr(0, 4) == "size"){
            quadtree.size();
        }
	}
	return 0;
}