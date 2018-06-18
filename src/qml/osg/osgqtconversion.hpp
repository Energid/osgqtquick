//------------------------------------------------------------------------------
// Copyright (c) 2017 Energid Technologies. All rights reserved.
//
/// @file osgQtConversion.h
/// @namespace OsgQtConversion
//
//------------------------------------------------------------------------------
#ifndef OSGQTCONVERSION_H
#define OSGQTCONVERSION_H

#include <osgQtQml/Export>

#include <QtGui/QColor>
#include <QtGui/QVector2D>
#include <QtGui/QVector3D>
#include <QtGui/QVector4D>
#include <QtGui/QMatrix4x4>
#include <QtGui/QQuaternion>

#include <osg/Vec4>
#include <osg/Vec2>
#include <osg/Vec3>
#include <osg/Matrix>
#include <osg/Quat>

/// \brief Provides functions to convert between Qt and OSG data types.
/// \ingroup Ec_Qml_OsgCore
namespace OsgQtConversion
{
   ///
   /// \brief toOsg Converts a QColor to osg::Vec4 (OSG color).
   /// \param color QColor
   /// \return Color as osg::Vec4.
   ///
   inline OSGQTQML_EXPORT const osg::Vec4 toOsg
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
   inline OSGQTQML_EXPORT const QColor toQColor
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
   inline OSGQTQML_EXPORT osg::Vec4 toOsg
      (
      const QVector4D &vect
      )
   {
      return osg::Vec4(vect[0], vect[1], vect[2], vect[3]);
   }

   /// \brief Returns a QVector4D by value for given osg::Vec4.
   inline OSGQTQML_EXPORT QVector4D toQt
      (
      const osg::Vec4& vect
      )
   {
      return QVector4D(vect.x(), vect.y(), vect.z(), vect.w());
   }

   ///
   /// \brief toOsg Converts a vector of QVector4D to equivalent osg vect3d  value
   /// \param vector QVector4D value.
   /// \return osg::Vec3d value.
   ///
   inline OSGQTQML_EXPORT osg::Vec2 toOsg
      (
      const QVector2D &vect
      )
   {
      return osg::Vec2(vect[0], vect[1]);
   }

   /// \brief Returns a QVector4D by value for given osg::Vec4.
   inline OSGQTQML_EXPORT QVector2D toQt
      (
      const osg::Vec2& vect
      )
   {
      return QVector2D(vect.x(), vect.y());
   }

   ///
   /// \brief toOsg Converts a vector of QVector3D to equivalent osg vect3d  value
   /// \param vector QVector3D value.
   /// \return osg::Vec3d value.
   ///
   inline OSGQTQML_EXPORT osg::Vec3 toOsg
      (
      const QVector3D &vect
      )
   {
      return osg::Vec3(vect[0], vect[1], vect[2]);
   }

   ///
   /// \brief QVector3D Converts a vector of osg::Vec3 to equivalent QVector3D  value
   /// \param vector osg::Vec3 value.
   /// \return QVector3D value.
   ///
   inline OSGQTQML_EXPORT QVector3D toQt
      (
      const osg::Vec3 &vect
      )
   {
      return QVector3D(vect[0], vect[1], vect[2]);
   }

   ///
   /// \brief toOsg Converts a matrix4*4 of QMatrix4x4 to equivalent osg osg::Matrix  value
   /// \param vector QMatrix4x4 value.
   /// \return osg::Matrix value.
   ///
   inline OSGQTQML_EXPORT osg::Matrix toOsg
      (
      const QMatrix4x4 &mat
      )
   {
      return osg::Matrix(mat(0,0), mat(1,0), mat(2,0), mat(3,0),
                         mat(0,1), mat(1,1), mat(2,1), mat(3,1),
                         mat(0,2), mat(1,2), mat(2,2), mat(3,2),
                         mat(0,3), mat(1,3), mat(2,3), mat(3,3));
   }

   /// \brief Returns a QMatrix4x4 by value for given osg::Matrix.
   inline OSGQTQML_EXPORT QMatrix4x4 toQt
      (
      const osg::Matrix& osgMat
      )
   {
      return QMatrix4x4(osgMat(0,0), osgMat(1,0), osgMat(2,0), osgMat(3,0),
                        osgMat(0,1), osgMat(1,1), osgMat(2,1), osgMat(3,1),
                        osgMat(0,2), osgMat(1,2), osgMat(2,2), osgMat(3,2),
                        osgMat(0,3), osgMat(1,3), osgMat(2,3), osgMat(3,3));
   }

   ///
   /// \brief toOsg Converts a Quaternion of QQuaternion to equivalent  osg::Quat  value
   /// \param vector QQuaternion value.
   /// \return osg::Quat value.
   ///
   inline OSGQTQML_EXPORT osg::Quat toOsg
      (
      const QQuaternion &quatValue
      )
   {
      return osg::Quat(quatValue.x(), quatValue.y(), quatValue.z(), quatValue.scalar());
   }

   /// \brief Returns a QQuaternion by value for given osg::Quat.
   inline OSGQTQML_EXPORT QQuaternion toQt
      (
      const osg::Quat& osgQuatVal
      )
   {
      return QQuaternion(osgQuatVal.w(), osgQuatVal.x(), osgQuatVal.y(), osgQuatVal.z());
   }
}

#endif // OSGQTCONVERSION_H
