// SearchNoStar.h
// ======^^^^^^==
// OEDMONDSON
// Declaration of Search class for NoStar algorithm
//

//  NOTE - There is no such thing as the NoStar search algorithm
//         I have implemented it as a pattern for you to follow


#ifndef _SEARCH_A_STAR_
#define _SEARCH_A_STAR_

#include "Definitions.h"  // Type definitions
#include "fileReading.h"
#include "Search.h"       // Base (=interface) class definition
#include <algorithm>
// NoStar search class definition

/* TODO - Replace this class with classes to implement real search algorithms*/

// Inherit from interface and provide implementation for 0* algorithm
class CSearchNoStar : public ISearch
{
public:
	//Below for access to lists.
	bool FindPath(TerrainMap& terrain, unique_ptr<SNode> p_start, unique_ptr<SNode> p_goal, NodeList& p_path, CGameClass MapVisual);
private:

	void Push(unique_ptr<SNode> p_tmp, int currentMapValue, int xGoal, int yGoal, int xIncrease, int yIncrease);



};


#endif _SEARCH_A_STAR_
