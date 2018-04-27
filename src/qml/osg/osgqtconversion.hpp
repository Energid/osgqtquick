//------------------------------------------------------------------------------
// Copyright (c) 2017 Energid Technologies. All rights reserved.
//
/// @file ecOsgQtConversion.h
/// @namespace EcOsgQtConversion
//
//------------------------------------------------------------------------------
#ifndef OSGQTCONVERSION_H
#define OSGQTCONVERSION_H


#include <QtCore/qglobal.h>
#include <osg/Vec4>
#include <osg/Vec2d>
#include <osg/Vec3d>
#include <QtGui/QColor>
#include <QtGui/QVector2D>
#include <QtGui/QVector3D>
#include <QtGui/QVector4D>
//#include <boost/numeric/conversion/cast.hpp>

/// \brief Provides functions to convert between Qt and OSG data types.
/// \ingroup Ec_Qml_OsgCore
namespace OsgQtConversion
{
   ///
   /// \brief toOsg Converts a QColor to osg::Vec4 (OSG color).
   /// \param color QColor
   /// \return Color as osg::Vec4.
   ///
   inline /*OSGQTQML_EXPORT*/ const osg::Vec4 toOsg
      (
      const QColor& color
      )
   {
      return osg::Vec4(color.redF(), color.greenF(), color.blueF(), color.alphaF());
   }

   ///
   /// \brief toQt Converts a color on osg (osg::Vec4) to a QColor value
   /// \param color osg::Vec4 value representing the color.
   /// \return QColor value.
   ///
   inline /*OSGQTQML_EXPORT*/ const QColor toQColor
      (
      const osg::Vec4& color
      )
   {
      return QColor::fromRgbF(color.r(), color.g(), color.b(), color.a());
   }

   ///
   /// \brief toOsg Converts a vector of QVector4D to equivalent osg vect3d  value
   /// \param vector QVector4D value.
   /// \return osg::Vec3d value.
   ///
   inline /*OSGQTQML_EXPORT*/ osg::Vec4 toOsg
      (
      const QVector4D &vect
      )
   {
      return osg::Vec4(vect[0], vect[1], vect[2], vect[3]);
   }

   ///
   /// \brief toOsg Converts a vector of QVector4D to equivalent osg vect3d  value
   /// \param vector QVector4D value.
   /// \return osg::Vec3d value.
   ///
   inline /*OSGQTQML_EXPORT*/ osg::Vec2d toOsg
      (
      const QVector2D &vect
      )
   {
      return osg::Vec2d(vect[0], vect[1]);
   }

   ///
   /// \brief toOsg Converts a vector of QVector3D to equivalent osg vect3d  value
   /// \param vector QVector3D value.
   /// \return osg::Vec3d value.
   ///
   inline /*OSGQTQML_EXPORT*/ osg::Vec3f toOsg
      (
      const QVector3D &vect
      )
   {
      return osg::Vec3f(vect[0], vect[1], vect[2]);
   }

   ///
   /// \brief QVector3D Converts a vector of osg::Vec3d to equivalent QVector3D  value
   /// \param vector osg::Vec3f value.
   /// \return QVector3D value.
   ///
   inline /*OSGQTQML_EXPORT*/ QVector3D toQt
      (
      const osg::Vec3f &vect
      )
   {
      return QVector3D(vect[0], vect[1], vect[2]);
   }

   ///
   /// \brief QVector3D Converts a vector of osg::Vec3d to equivalent QVector3D  value
   /// \param vector osg::Vec3d value.
   /// \return QVector3D value.
   ///
   inline /*OSGQTQML_EXPORT*/ QVector3D toQt
      (
      const osg::Vec3d &vect
      )
   {
      //return QVector3D(boost::numeric_cast<float>(vect[0]), boost::numeric_cast<float>(vect[1]), boost::numeric_cast<float>(vect[2]));

       return QVector3D((vect[0]), (vect[1]), (vect[2]));
   }

   /// \brief Returns a QVector4D by value for given osg::Vec4.
   inline /*OSGQTQML_EXPORT*/ QVector4D toQt
      (
      const osg::Vec4& vect
      )
   {
      return QVector4D(vect.x(), vect.y(), vect.z(), vect.w());
   }

   /// \brief Returns a QVector4D by value for given osg::Vec4.
   inline /*OSGQTQML_EXPORT*/ QVector2D toQt
      (
      const osg::Vec2d& vect
      )
   {
      return QVector2D(vect.x(), vect.y());
   }
}

#endif // OSGQTCONVERSION_H
