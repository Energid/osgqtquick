//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightindex.h
/// @class LightQtQmlIndex
//
//------------------------------------------------------------------------------
#ifndef LightQtQmlIndex_H
#define LightQtQmlIndex_H

#include "light.hpp"

#include "stateattributeindex.hpp"

#include <osg/Light>

namespace osg {
///
/// \brief Index class for API mapping between LightQtQml and osg::Light.
///
class OSGQTQML_EXPORT LightQtQml::Index :
   public StateAttributeQtQml::Index
{
public:
   typedef osg::Light OType;
   typedef LightQtQml QType;
   friend class LightQtQml;

public:

   /// Constructor
   Index
      (
      osg::Light *pObject = 0
      );

   /// Executes when component initialization begins.
   void classBegin
      (
      );

};

}

#endif // LightQtQmlIndex_H
