// SearchFactory.h
// ===============
//OEDMONDSON
// Factory function declaration to create CSearchXXX objects 
//

#ifndef _SEARCH_FACTORY_
#define _SEARCH_FACTORY_

#include "Search.h" // Search interface class
#include "fileReading.h"
#include "visualMethod.h"
// List of implemented seach algorithms
enum ESearchType
{
	// BreadthFirst,
	// Dijkstra,
	// AStar,

	/* TODO - Add type elements for each implemented search */

	SearchNoStar, // Not a real algorithm - remove when ready! 
//	FirstBest, //Just some generic key-words for future expansion.
Dijkstra,
EndSearch,
};


// Factory function to create CSearchXXX object where XXX is the given search type
ISearch* NewSearch(ESearchType search, CFileMap map, CGameClass mapVisual);
#endif