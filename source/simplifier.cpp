#include "simplifier.h"
#include <iostream>
using namespace std;

#define SIZE 4

simplifier::simplifier(map m) { m.getMatrix(matrix); }
simplifier::~simplifier(){}

// Ok Ok Ok! Honestly this funciton is not mine! but i changed it a little :)
void simplifier::makeCubes(superList &groups, int i, int j)
{
    list group;
    Pair temp;
    bool found = false;

    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    temp.i = i; temp.j = j;
    group.append(temp);

    for (unsigned int k = 0; k < SIZE; ++k)
    {
        // Doual
        if(matrix[(i+d[k][0]+4)%4][(j+d[k][1]+4)%4] == 1)
        {
            temp.i = (i+d[k][0]+4)%4; temp.j = (j+d[k][1]+4)%4;
            group.append(temp);

            // Linear quad
            if(matrix[(i+2*d[k][0]+4)%4][(j+2*d[k][1]+4)%4] == 1 && 
				matrix[(i+3*d[k][0]+4)%4][(j+3*d[k][1]+4)%4] == 1)
            {
                temp.i = (i+2*d[k][0]+4)%4; temp.j =(j+2*d[k][1]+4)%4;
                group.append(temp);
                temp.i = (i+3*d[k][0]+4)%4; temp.j =(j+3*d[k][1]+4)%4;
                group.append(temp);
                
                // Octant
                if(matrix[(i+0*d[k][0]+d[(k+1)%4][0]+4)%4][(j+0*d[k][1]+d[(k+1)%4][1]+4)%4] == 1 && 
						matrix[(i+1*d[k][0]+d[(k+1)%4][0]+4)%4][(j+1*d[k][1]+d[(k+1)%4][1]+4)%4] == 1 && 
						matrix[(i+2*d[k][0]+d[(k+1)%4][0]+4)%4][(j+2*d[k][1]+d[(k+1)%4][1]+4)%4] == 1 && 
						matrix[(i+3*d[k][0]+d[(k+1)%4][0]+4)%4][(j+3*d[k][1]+d[(k+1)%4][1]+4)%4] == 1)
                        {
							temp.i = (i+0*d[k][0]+d[(k+1)%4][0]+4)%4; temp.j =(j+0*d[k][1]+d[(k+1)%4][1]+4)%4;
							group.append(temp);

							temp.i = (i+1*d[k][0]+d[(k+1)%4][0]+4)%4; temp.j =(j+1*d[k][1]+d[(k+1)%4][1]+4)%4;
							group.append(temp);	

							temp.i = (i+2*d[k][0]+d[(k+1)%4][0]+4)%4; temp.j =(j+2*d[k][1]+d[(k+1)%4][1]+4)%4;
							group.append(temp);

							temp.i = (i+3*d[k][0]+d[(k+1)%4][0]+4)%4; temp.j =(j+3*d[k][1]+d[(k+1)%4][1]+4)%4;
							group.append(temp);	  
                        }
                        groups.append(group);
                        group.clear();
                        found = true;
                        break;
            }
			// square quad
			if(matrix[(i+0*d[k][0]+d[(k+1)%4][0]+4)%4][(j+0*d[k][1]+d[(k+1)%4][1]+4)%4] == 1 && 
				matrix[(i+1*d[k][0]+d[(k+1)%4][0]+4)%4][(j+1*d[k][1]+d[(k+1)%4][1]+4)%4] == 1){
					temp.i = (i+0*d[k][0]+d[(k+1)%4][0]+4)%4; temp.j =(j+0*d[k][1]+d[(k+1)%4][1]+4)%4;
					group.append(temp);

					temp.i = (i+1*d[k][0]+d[(k+1)%4][0]+4)%4; temp.j =(j+1*d[k][1]+d[(k+1)%4][1]+4)%4;
					group.append(temp);	
			}
			groups.append(group);
			group.clear();
			temp.i = i; temp.j = j;
			group.append(temp);
			found = true;
		} 
	}	
	// If there's no group, push the single
	if(!found)
		groups.append(group);
}

bool simplifier::subset(list l1, list l2)
{
	// Check if all members of l1 are in l2
	for(unsigned int i = 0; i < l1.size(); ++i)
	{
		bool found = false;
		
		for(unsigned int j = 0; j < l2.size(); ++j)
			if(l1.get(i).i*SIZE + l1.get(i).j == l2.get(j).i*SIZE + l2.get(j).j)
			{
				found = true;
				break;
			}

		// If not found it means that l1 and l2 aren't subsets
		if(!found)
			return false;
	}
	return true;
}

bool simplifier::commonPair(Pair pair, superList groups, int skip)
{
	// Searchig for common pairs
	for(unsigned int i = 0; i < groups.size(); ++i)
		for(unsigned int j = 0; j < groups.get(i).size(); ++j)
			// Dont compare a group pairs to itself!!! (i != skip)
			if(i != skip && groups.get(i).get(j).i*SIZE + groups.get(i).get(j).j == pair.i*SIZE + pair.j)
				return true;

	// If there's no common pairs then return false
	return false;
}

void simplifier::optimize(superList &groups)
{
	superList temp;
	// Remove subsets
	for(unsigned int i = 0; i < groups.size(); ++i)
	{
		bool sub = false;
		for (unsigned int j = 0; j < temp.size(); ++j)
			// Ignore itself (i != j)
			if(i != j && subset(groups.get(i), temp.get(j)))
			{
				sub = true;
				break;
			}

		if (!sub)
			temp.append(groups.get(i));
	}
	groups = temp;
	// ---------------------------------------------------

	// Remove common pairs
	temp.clear(); // We wanna use temp another time! so clear it and use again :-)
	bool common;
	for(int i = 0; i < groups.size(); ++i)
	{
		// Check every group in groups and find that if
		// there are some elements that are placed in several cubes
		common = true;
		for(int j = 0; j < groups.get(i).size(); j++)
			if(!commonPair(groups.get(i).get(j), groups, i))
			{
				common = false;
				break;
			}

		if(!common)
			temp.append(groups.get(i));
	}
	groups = temp;
}

string simplifier::parseToExp(list group)
{

	string result;
	string columns[] = {"cd","cD","CD","Cd"};
	string rows[] = {"ab","aB","AB","Ab"};

	string temp2 = columns[group.get(0).j] + rows[group.get(0).i];

	for(unsigned int i = 0; i < group.size(); ++i)
	{
		result = "";
		string temp1 = columns[group.get(i).j] + rows[group.get(i).i];

		for(unsigned int j = 0; j < temp2.size(); ++j)
			if(temp1.find(temp2[j]) != -1)
				result += temp2[j];

		temp2 = result;
	}

	return result;
}

void simplifier::run()
{
	// First : make a group and find cubes then store them in the group
    superList groups;
    for (int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j){	
			if(matrix[i][j] == 1)
				makeCubes(groups, i, j);			
		}
	}
	
	// Optimize : remove redundant cubes
	optimize(groups);

	// Print cubes
	cout << "\nCubes:\n";
	groups.print();
	cout << "\n";

	// Make result expression and print it!
	bool firstExp = true;
	string result;
	for (int i = 0; i < groups.size(); i++)
	{
		if (!firstExp)
			result = result + "+" + parseToExp(groups.get(i));
		else
		{
			firstExp = false;
			result = result + parseToExp(groups.get(i));
		}
	}
	// Yooohoooo we did it! :))
	cout << result << "\n";
}