// Search.h
// ========
//OEDMONDSON
// Interface for all search classes
//
#pragma once //Breaks when I use #IfnDef


#include "Definitions.h" // type definitions
#include <algorithm>
#include "visualMethod.h"
// ISearch interface class - cannot be instantiated
// Implementation classes for specific search algorithms should inherit from this interface
class ISearch
{
public:
	// Interfaces don't need a constructor - makes sense really, given they cannot be instantiated.

	// They DO need a virtual destructor if there are other virtual functions in the interface.
	// This compels derived objects destructors to be called as appropriate.
	// However, at the interface level, there is nothing to do, so the body is empty.
	virtual ~ISearch() {}

	// PATH FINDING FUNCTIONS
	// ----------------------

	// Constructs the path from start to goal for the given terrain
	// Pure Virtual function to be implemented in derived class.
	virtual bool FindPath(TerrainMap& terrain, unique_ptr<SNode> start, unique_ptr<SNode> goal, NodeList& path, CGameClass mapVisual) = 0;

	//virtual void virtualOutput() = 0;
	//virtual void step();
	//irtual void tempName();
	/* TODO - Only for high marks
	   Add a pure virtual function declaration to perform one iteration of the path-finding loop.
	   This is in support of showing the search in real time.
	   The main program will need to display somehow:
	   - the open list
	   - the closed list
	   - the path to the current node */

protected:

	bool isClosedList(int xVal, int yVal, int score, SNode* parent); //Goes through the closedList to confirm if the sent value is there.
	bool isOpenList(int xVal, int yVal);//Goes through the open list to confirm the sent value is there,
	void TextOutput(NodeList& path); //Outputs the path into a text file.
	NodeList openList;
	unique_ptr <SNode> pCurrentNode;
	NodeList closedList;

	void openSort() //Sorts the list
	{
		sort(openList.begin(), openList.end(), [](unique_ptr<SNode>& lhs,
			unique_ptr<SNode>& rhs) { return lhs->score + lhs->terrainCost < rhs->score + rhs->terrainCost; });
	}



	//std::unique_ptr<SCoords> push(std::unique_ptr <SCoords> t);

	int sortCount = 0;

private:
	NodeList* textPath;
	NodeList* finalPathImport(NodeList& path);
	const float kUpdateRate = 1.0f; //This is the speed of the real-time update.


};