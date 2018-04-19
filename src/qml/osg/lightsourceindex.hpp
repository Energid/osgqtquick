//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightsource.hpp
/// @class LightSourceQtQml
//
//------------------------------------------------------------------------------
#ifndef LightSourceQtQmlIndex_H
#define LightSourceQtQmlIndex_H


#include "lightsource.hpp"


#include <osg/GroupQtQmlIndex>
#include <osg/LightSource>

///
/// \brief Provides an object/API mapping between LightModelQtQml and osg::LightSource.
///
class OSGQTQML_EXPORT LightSourceQtQml::Index :
   public GroupQtQml::Index
{
public:
   typedef osg::LightSource OType;
   typedef LightSourceQtQml QType;
   friend class LightSourceQtQml;

public:

   /// Constructor
   Index
      (
      osg::LightSource *pObject = 0
      );

   /// Executes when component initialization begins.
   void classBegin
      (
      );

};


#endif // LightModelQtQmlIndex_H
