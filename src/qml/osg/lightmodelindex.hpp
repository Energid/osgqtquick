//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightmodel.h
/// @class LightModelQtQml
//
//------------------------------------------------------------------------------
#ifndef LightModelQtQmlIndex_H
#define LightModelQtQmlIndex_H


#include "lightmodel.hpp"


#include "stateattributeindex.hpp"

#include <osg/LightModel>

///
/// \brief Index class for mapping API between LightModelQtQml and osg::LightModel
///
class OSGQTQML_EXPORT LightModelQtQml::Index :
   public StateAttributeQtQml::Index
{
public:
   typedef osg::LightModel OType;
   typedef LightModelQtQml QType;
   friend class LightModelQtQml;

public:

   /// Constructor
   Index
      (
      osg::LightModel *pObject = 0
      );

   /// Executes this code when the component initialization is started
   void classBegin
      (
      );

};


#endif // LightModelQtQmlIndex_H
