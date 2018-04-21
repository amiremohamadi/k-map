#include "simplifier.h"
#include <iostream>
using namespace std;

simplifier::simplifier(map m) { m.getMatrix(matrix); } //????
simplifier::~simplifier(){}

void simplifier::makeCubes(superList &groups, int i, int j)
{
    list group;
    Pair temp;
    bool found = false;

    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    temp.i = i; temp.j = j;
    group.append(temp);

    for (unsigned int k = 0; k < 4; ++k)
    {
        // Doual
        if(matrix[(i+d[k][0]+4)%4][(j+d[k][1]+4)%4] == 1)
        {
            temp.i = (i+d[k][0]+4)%4; temp.j = (j+d[k][1]+4)%4;
            group.append(temp);

            // Linear quad
            if(matrix[(i+2*d[k][0]+4)%4][(j+2*d[k][1]+4)%4] == 1 && 
				matrix[(i+3*d[k][0+4])%4][(j+3*d[k][1]+4)%4] == 1)
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
	// If there's no group, push the unit
	if(!found)
		groups.append(group);
}

void simplifier::run()
{

	for (int i = 0; i < 4; ++i)
	{	for (int j = 0; j < 4; ++j)
			cout << matrix[i][j] << " ";
	cout << "\n";}
    superList groups;
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++){	
			if(matrix[i][j] == 1)
				makeCubes(groups,i,j);			
		}
	}
    groups.print();
}