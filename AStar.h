#pragma once
#ifndef __classLoad__
#define __classLoad__

#include <memory>
#include "Definitions.h";
#include <iostream>
#include <list>
#include <iterator>
#include <deque>
#include <algorithm>
#include "fileReading.h"
/**0-1 are X-Y**/
const int MAPSIZE[2] = { 10,10 };

class CSearchNoStar
{
public:
	//Below for access to lists.
	void basic(c_fileMap map);
private:
	void pop() { openList.pop_front(); }
	void reset() { openList.clear(); }
	bool isEmpty()
	{
		if (openList.empty())
		{
			return true;
		}
		return false;
	}
	void raw(SCoords* t) {};
	bool isClosed(SCoords current);

	std::unique_ptr<SCoords> push(std::unique_ptr <SCoords> t);
	std::unique_ptr<SCoords> setup(std::unique_ptr <SCoords> t);


	SCoords* prior;
	NodeList openList;
	NodeList currentNode;
	NodeList closedList;
};


std::unique_ptr<SCoords> CSearchNoStar::push(std::unique_ptr <SCoords> t)
{
	openList.push_back(move(t));
	std::unique_ptr <SCoords> tmp(new SCoords);
	t.reset(new SCoords);
	return move(t);
}

bool CSearchNoStar::isClosed(SCoords current)
{

	for (auto p = openList.begin(); p != openList.end(); ++p)
	{
		if ((*p)->x == current.x && (*p)->y == current.y)	//openList[p].x == current.x && var.y == current.y)
		{
			return true;
		}
	}
	return false;
}

void CSearchNoStar::basic(c_fileMap map)
{
	std::unique_ptr <SCoords> tmp(new SCoords);

	tmp->x = map.GetStartX();
	tmp->y = map.GetStartY();
	currentNode.push_front(move(tmp));
	tmp.reset(new SCoords);

	while (currentNode.front()->x != map.GetEndX() && currentNode.front()->y != map.GetEndY())
	{
		tmp->x = currentNode.front()->x;
		tmp->y = currentNode.front()->y;
		/*
		Goals:
		-Check if the northern, western, eastern and southern Nodes are on the closedList or Out_Of_Bounds;
		-When identified, set the currentNode as the parent to the identified Node and push the currentNode into the closedList, letting the identified Node take its place as the CurrentNode.
		-Before doing the above task, make sure it's the closest possible route with the lowest cost.
		*/

		if (tmp->x + 1 < map.GetEndX())
		{
			//tmp->parent = std::get(prior->parent);
			//tmp->x = currentX;
			//tmp->y = currentY;

		}
		if (tmp->x - 1 > 0)
		{

		}
		if (tmp->y + 1 < map.GetEndY())
		{

		}
		if (tmp->y - 1 > 0)
		{

		}

	}


	map.GetMap()[map.GetStartX()][map.GetStartY()];


	setup(move(tmp));

	tmp = nullptr;


}



#endif 