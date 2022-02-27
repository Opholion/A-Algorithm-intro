// SearchFactory.cpp
// =================
//OEDMONDSON
// Factory function implementation to create CSearchXXX objects 
//

#include "SearchAStar.h" // NoStar search class
#include "fileReading.h"
#include "Dijkstra.hpp"

/* TODO - include each implemented search class here */


#include "SearchFactory.h" // Factory declarations
#include <iostream>
// Create new search object of the given type and return a pointer to it.
// Note the returned pointer type is the base class. This is how we implement polymorphism.



ISearch* NewSearch(ESearchType search, CFileMap map, CGameClass mapVisual)
{
	switch (search)
	{
	case SearchNoStar:
	{
		//FindPath(TerrainMap & terrain, unique_ptr<SCoords> start, unique_ptr<SCoords> goal, NodeList & path)

		return new CSearchNoStar();
	}

	//case FirstBest:
	//{
	//	return new CSearchFirstBest();
	//}
	case Dijkstra:
	{
		//Create another ASTAR but change the heuristic to return 1.

		return new CSearchDijkstra();
	}
	}


	return nullptr;
}
