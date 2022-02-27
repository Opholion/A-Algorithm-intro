// SearchFactory.cpp
// =================
//
// Factory function implementation to create CSearchXXX objects 
//

/* TODO - include each implemented search class here */
//#include "SearchIsStep.hpp" // Factory declarations
//#include <iostream>
//#include "Definitions.h"
//// Create new search object of the given type and return a pointer to it.
//// Note the returned pointer type is the base class. This is how we implement polymorphism.
//
//
//
//GameStepper* NewSearch(ESearchType search, c_fileMap map, NoStepGame mapVisual)
//{
//	switch (search)
//	{
//	case SearchNoStar:
//	{
//		//FindPath(TerrainMap & terrain, unique_ptr<SCoords> start, unique_ptr<SCoords> goal, NodeList & path)
//
//		return new CSearchNoStar();
//	}
//
//	//case FirstBest:
//	//{
//	//	return new CSearchFirstBest();
//	//}
//	case Dijkstra:
//	{
//		//Create another ASTAR but change the heuristic to return 1.
//
//		return new CSearchDijkstra();
//	}
//
//	case EndSearch:
//	{
//
//		return new CSearchDijkstra(); //** This is to close the game engine.
//	}
//	}
//
//
//	return nullptr;
//}
//