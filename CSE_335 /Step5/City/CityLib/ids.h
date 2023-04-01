/**
 * @file ids.h
 * @author Charles B. Owen
 * ID values for menus and other controls
 */

#ifndef CITY_IDS_H
#define CITY_IDS_H

/**
 * Menu id values
 */
enum IDs {
    /// View>Outlines menu option
    IDM_VIEW_OUTLINES = wxID_HIGHEST + 1,

    /// View>City Report menu option
    IDM_VIEW_CITYREPORT,

    /// Landscaping>Grass menu option
    IDM_LANDSCAPING_GRASS,

    /// Lanscaping>Road menu option
    IDM_LANDSCAPING_ROAD,

    /// Landscaping>Tall Grass menu option
    IDM_LANDSCAPING_TALLGRASS,

    /// Landscaping>Sparty Statue menu option
    IDM_LANDSCAPING_SPARTYSTATUE,

    /// Landscaping>Tree menu option
    IDM_LANDSCAPING_TREE,

    /// Landscaping>Trees menu option
    IDM_LANDSCAPING_TREES,

    /// Landscaping>Big Trees menu option
    IDM_LANDSCAPING_BIGTREES,

    /// Landscaping>Garden menu option
    IDM_LANDSCAPING_GARDEN,

    /// Buildings->Farm House menu option
    IDM_BUILDINGS_FARMHOUSE,

    /// Buildings>Blacksmith Shop menu option
    IDM_BUILDINGS_BLACKSMITHSHOP,

    /// Buildines>Brown House menu option
    IDM_BUILDINGS_BROWNHOUSE,

    /// Buildines>Yellow House menu optino
    IDM_BUILDINGS_YELLOWHOUSE,

    /// Buildings>Fire Station menu option
    IDM_BUILDINGS_FIRESTATION,

    /// Buildings>Hospital menu option
    IDM_BUILDINGS_HOSPITAL,

    /// Buildines>Market menu option
    IDM_BUILDINGS_MARKET,

    /// Buildings>Condos menu option
    IDM_BUILDINGS_CONDOS,

    /// Businesses>Coal Mine menu option
    IDM_BUSINESSES_COALMINE,

    /// Businesses>Rocket Pad menu option
    IDM_BUSINESSES_ROCKETPAD,
    IDM_BUSINESSES_HAULCOAL,

    IDM_BUILDINGS_COUNT,
    IDM_BUSINESSES_BOOST
};

#endif //CITY_IDS_H
