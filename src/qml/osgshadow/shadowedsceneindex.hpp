//------------------------------------------------------------------------------
// Copyright (c) 2018 Energid Technologies. All rights reserved.
//
/// @file lightindex.h
/// @class ShadowedSceneQtQmlIndex
//
//------------------------------------------------------------------------------
#ifndef ShadowedSceneQtQmlIndex_H
#define ShadowedSceneQtQmlIndex_H

#include "shadowedscene.hpp"

#include <osg/GroupQtQmlIndex>



namespace osgShadow {
///
/// \brief Index class for API mapping between ShadowedSceneQtQml and osg::Light.
///
class OSGQTQML_EXPORT ShadowedSceneQtQml::Index :
   public GroupQtQml::Index
{
public:
   typedef osgShadow::ShadowedScene OType;
   typedef ShadowedSceneQtQml QType;
   friend class ShadowedSceneQtQml;

public:

   /// Constructor
   Index
      (
      osgShadow::ShadowedScene *pObject = 0
      );

   /// Executes when component initialization begins.
   void classBegin
      (
      );

};

}

#endif // ShadowedSceneQtQmlIndex_H
