// SearchNoStar.cpp
// ======^^^^^^====
// OEDMONDSON
// Implementation of Search class for NoStar algorithm
//

//  NOTE - There is no such thing as the NoStar search algorithm
//         I have implemented it as a pattern for you to follow

#include "SearchAStar.h" // Declaration of this class
#include "visualMethod.h"
#include <iostream>
/* TODO - Replace this class with classes to implement real search algorithms*/


// This function takes ownership of the start and goal pointers that are passed in from the calling code.
// Ownership is not returned at the end, so the start and goal nodes are consumed.
// The Path is returned through the reference parameter.

#include <string>

void  CSearchNoStar::Push(unique_ptr<SNode> pTmp, int currentMapValue, int xGoal, int yGoal, int xIncrease, int yIncrease)
{
	pTmp->x = pCurrentNode->x + xIncrease;
	pTmp->y = pCurrentNode->y + yIncrease;
	pTmp->score = pCurrentNode->score;
	pTmp->parent = pCurrentNode.get();
	if (pTmp->parent != nullptr)
	{
		pTmp->terrainCost = pTmp->parent->terrainCost + currentMapValue;
	}

	if (isClosedList(pTmp->x, pTmp->y, currentMapValue + pTmp->score, move(pTmp->parent)) && isOpenList(pTmp->x, pTmp->y) && currentMapValue != 0)
	{
		pTmp->score = abs(pTmp->x - xGoal) + abs(pTmp->y - yGoal) + currentMapValue;

		openList.push_back(move(pTmp));
		pTmp.reset(new SNode);
		pTmp->x = openList.back()->x;
		pTmp->y = openList.back()->y;
		pTmp->parent = openList.back()->parent;
	}
}



bool CSearchNoStar::FindPath(TerrainMap& pTerrain, unique_ptr<SNode> pStart, unique_ptr<SNode> goal, NodeList& path, CGameClass mapVisual)
{
	// Rather than finding a real path, my made-up No Star algorithm constructs some nodes and calls them a path.



	if (pTerrain[pStart->y][pStart->x] == Wall || pTerrain[goal->y][goal->x] == Wall)
	{
		return false;
	}


	int temp = pStart->x;
	pStart->x = pStart->y;
	pStart->y = temp;


	pCurrentNode = move(pStart);
	pCurrentNode->score = abs(pCurrentNode->x - goal->y) + abs(pCurrentNode->y - goal->x);


	bool isFound = false;
	do
	{

		if (pCurrentNode->y + 1 < pTerrain[0].size())
		{
			pStart.reset(new SNode);
			Push(move(pStart), pTerrain[pCurrentNode->x][pCurrentNode->y + 1], goal->y, goal->x, NULL, 1);
		}
		if (pCurrentNode->y - 1 >= 0)
		{
			pStart.reset(new SNode);
			Push(move(pStart), pTerrain[pCurrentNode->x][pCurrentNode->y - 1], goal->y, goal->x, NULL, -1);
		}
		if (pCurrentNode->x + 1 < pTerrain.size())
		{
			pStart.reset(new SNode);
			Push(move(pStart), pTerrain[pCurrentNode->x + 1][pCurrentNode->y], goal->y, goal->x, 1, NULL);
		}
		if (pCurrentNode->x - 1 >= 0)
		{
			pStart.reset(new SNode);
			Push(move(pStart), pTerrain[pCurrentNode->x - 1][pCurrentNode->y], goal->y, goal->x, -1, NULL);
		}


		if (pCurrentNode->y == goal->x && pCurrentNode->x == goal->y)
		{
			isFound = true;
		}
		else
		{
			//If the openlist isn't empty then push the current node onto the closed list and sort the open list. Then take the curr
			if (!openList.empty())
			{
				++sortCount;
				openSort();


				closedList.push_back(move(pCurrentNode));
				pCurrentNode.reset(new SNode);
				pCurrentNode = move(openList.front());
				openList.pop_front();

				if (!mapVisual.IfFileReading())
				{
					cout << "X is: " << pCurrentNode->y << "/ Y is: " << pCurrentNode->x << "/ Score:" << pCurrentNode->score << "\n";
					mapVisual.GameSceneUpdate(pTerrain, pCurrentNode->y, pCurrentNode->x, 0);
					for (int i = 0; i < openList.size(); ++i)
					{
						mapVisual.GameSceneUpdate(pTerrain, openList[i]->y, openList[i]->x, 1);
					}
					for (int i = 0; i < closedList.size(); ++i)
					{
						mapVisual.GameSceneUpdate(pTerrain, closedList[i]->y, closedList[i]->x, 2);
					}

					while (mapVisual.GetFrameTime() < 1)
					{
						int i = 0;
					};//This is a 1 second delay.
					mapVisual.PathClean();
					mapVisual.ResetFrameTime();
				}
			}
			else
			{
				isFound = true;
			}


		}

	} while (!isFound);

	cout << "\nAmount of openList sorts: " << sortCount << "\n";


	path.push_front(move(pCurrentNode));

	if (path[0]->x == goal->y && path[0]->y == goal->x)
	{
		while (path[0]->parent != 0)
		{

			unique_ptr<SNode> tmp(new SNode);
			tmp->x = path[0]->parent->x;
			tmp->y = path[0]->parent->y;
			tmp->score = path[0]->parent->score;
			tmp->parent = path[0]->parent->parent;

			path.push_front(move(tmp));

			//tmp.reset(new SNode);
		}

		for (int i = 0; i < path.size(); ++i)
		{	//Seperated to make it easier to read code.
			cout << "X Val: " << path[i]->x << " ";
			cout << "Y Val: " << path[i]->y << "\n";

		}
		//Print origin// While-loop stops at the [1] position.
		//path.emplace_back(move(currentNode));
		TextOutput(move(path));

		return true;
	}
	return false;
}



