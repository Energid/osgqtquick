//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file StateAttributeQtQml.h
/// @class StateAttributeQtQml
//
//------------------------------------------------------------------------------
#ifndef StateAttributeQtQmlIndex_H
#define StateAttributeQtQmlIndex_H

#include "stateattribute.hpp"

#include <osg/ObjectQtQmlIndex>

#include <osg/StateAttribute>

namespace osg {

/// \brief Provides an object/API mapping between StateAttributeQtQml and osg::StateAttribute.
class OSGQTQML_EXPORT StateAttributeQtQml::Index :
   public ObjectQtQml::Index
{
public:
   typedef osg::StateAttribute OType;
   typedef StateAttributeQtQml QType;
   friend class StateAttributeQtQml;

public:

   /// Constructor
   Index
      (
      osg::StateAttribute *pObject = 0
      );
};

}


#endif // StateAttributeQtQmlIndex_H
