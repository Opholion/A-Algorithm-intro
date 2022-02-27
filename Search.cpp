//OEDMONDSON


#include "Search.h"
#include <iostream>
#include <fstream>
#include <string>
const string ISEARCH_TEXT_OUTPUT[6] = { "\n","AN ERROR HAS OCCURSED WHEN OUTPUTTING TEXT FILE", "output.txt", "Tiles crossed: [", "]\n", "coords.txt", };

NodeList* ISearch::finalPathImport(NodeList& path)
{
	unique_ptr<SNode> tmp(new SNode);
	tmp->x = pCurrentNode->x;
	tmp->y = pCurrentNode->y;
	tmp->score = pCurrentNode->x;
	//path.push_back(tmp); //Current attempts at pushing onto the path.
	return move(&path); /** Testing **/
}


//This will read through the path list and output it into a text file.
void ISearch::TextOutput(NodeList& prior)
{
	ofstream myfile;
	if (!myfile)
	{
		cout << ISEARCH_TEXT_OUTPUT[1];
	}
	else
	{
		myfile.open(ISEARCH_TEXT_OUTPUT[2]);
		for (int i = 0; i < prior.size(); ++i)
		{
			myfile << prior[i]->y << " ";
			myfile << prior[i]->x << ISEARCH_TEXT_OUTPUT[0] << ISEARCH_TEXT_OUTPUT[0];
		}

		cout << ISEARCH_TEXT_OUTPUT[3] << prior.size() << ISEARCH_TEXT_OUTPUT[4];
		myfile.close();
	}
}

//This searches through the closed list.
bool ISearch::isClosedList(int xVal, int yVal, int score, SNode* parent)
{
	int i = 0;
	while (i < closedList.size())
	{
		if (closedList[i]->x == xVal && closedList[i]->y == yVal)//If the current score is smaller than the possible paths score then override it.
		{
			return false;
		}
		++i;
	}
	return true;
}
bool ISearch::isOpenList(int xVal, int yVal)
{
	int i = 0;
	while (i < openList.size())
	{
		if (openList[i]->x == xVal && openList[i]->y == yVal)
		{
			return false;
		}
		++i;
	}
	return true;
}
