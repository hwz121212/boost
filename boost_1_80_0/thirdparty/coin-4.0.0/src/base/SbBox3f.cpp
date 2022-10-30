/**************************************************************************\
 * Copyright (c) Kongsberg Oil & Gas Technologies AS
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

/*!
  \class SbBox3f SbBox3f.h Inventor/SbBox3f.h
  \brief The SbBox3f class is an abstraction for an axis aligned 3 dimensional box.

  \ingroup base

  This box abstraction class is used by other entities in the Coin
  library for data exchange and storage. It provides a representation
  of the defining corners of a box in 3D space, with the sides aligned
  with the 3 principal axes.

  \sa SbBox2s, SbBox2f, SbBox2d, SbBox3s, SbBox3d, SbXfBox3f.
*/

#include <Inventor/SbBox3f.h>

#include <limits>

#include <Inventor/SbBox3d.h>
#include <Inventor/SbBox3s.h>
#include <Inventor/SbBox3i32.h>
#include <Inventor/SbMatrix.h>
#if COIN_DEBUG
#include <Inventor/errors/SoDebugError.h>
#endif // COIN_DEBUG

/*!
  \fn SbBox3f::SbBox3f(void)
  The default constructor makes an empty box.
*/

/*!
  \fn SbBox3f::SbBox3f(float minx, float miny, float minz, float maxx, float maxy, float maxz)

  Constructs a box with the given corners.

  \a minx should be less than \a maxx, \a miny should be less than
  \a maxy and \a minz should be less than \a maxz if you want to make
  a valid box.
*/

/*!
  \fn SbBox3f::SbBox3f(const SbVec3f & minval, const SbVec3f & maxval)

  Constructs a box with the given corners.

  The coordinates of \a min should be less than the coordinates of
  \a max if you want to make a valid box.
*/

/*!
  \fn SbBox3f & SbBox3f::setBounds(float minx, float miny, float minz, float maxx, float maxy, float maxz)

  Reset the boundaries of the box.

  \a minx should be less than \a maxx, \a miny should be less than
  \a maxy and \a minz should be less than \a maxz if you want to make
  a valid box.

  Returns reference to self.

  \sa getBounds().
*/

/*!
  \fn SbBox3f & SbBox3f::setBounds(const SbVec3f & minval, const SbVec3f & maxval)

  Reset the boundaries of the box with the given corners.

  The coordinates of \a min should be less than the coordinates of
  \a max if you want to make a valid box.

  Returns reference to self.

  \sa getBounds().
*/

/*!
  Reset the boundaries to the boundaries of the given \a box.

  Returns reference to self.

  \sa getBounds().
*/

SbBox3f &
SbBox3f::setBounds(const SbBox3d & box)
{
  if (box.isEmpty()) {
    makeEmpty();
  } else {
    minpt.setValue(box.getMin());
    maxpt.setValue(box.getMax());
  }
  return *this;
}

/*!
  Reset the boundaries to the boundaries of the given \a box.

  Returns reference to self.

  \sa getBounds().
*/

SbBox3f &
SbBox3f::setBounds(const SbBox3s & box)
{
  if (box.isEmpty()) {
    makeEmpty();
  } else {
    minpt.setValue(box.getMin());
    maxpt.setValue(box.getMax());
  }
  return *this;
}

/*!
  Reset the boundaries to the boundaries of the given \a box.

  Returns reference to self.

  \sa getBounds().
*/

SbBox3f &
SbBox3f::setBounds(const SbBox3i32 & box)
{
  if (box.isEmpty()) {
    makeEmpty();
  } else {
    minpt.setValue(box.getMin());
    maxpt.setValue(box.getMax());
  }
  return *this;
}

/*!
  \fn const SbVec3f & SbBox3f::getMin(void) const

  Returns the minimum point. This should usually be the lower left
  corner point of the box.

  \sa getOrigin(), getMax().
*/

/*!
  \fn const SbVec3f & SbBox3f::getMax(void) const

  Returns the maximum point. This should usually be the upper right
  corner point of the box.

  \sa getMin().
*/

/*!
  \fn SbVec3f & SbBox3f::getMin(void)

  Returns a modifiable reference the minimum point.
*/

/*!
  \fn SbVec3f & SbBox3f::getMax(void)

  Returns a modifiable reference the maximum point.
*/

/*!
  \fn SbVec3f SbBox3f::getCenter(void) const

  Returns the center point of the box.
*/

/*!
  Extend the boundaries of the box by the given point, i.e. make the
  point fit inside the box if it isn't already so.
*/
void
SbBox3f::extendBy(const SbVec3f & point)
{
  if (this->isEmpty()) {
    this->setBounds(point, point);
  }
  else {
    // The explicit casts are done to humour the HPUX aCC compiler,
    // which will otherwise say ``Template deduction failed to find a
    // match for the call to 'SbMin'''. mortene.
  this->minpt.setValue(SbMin(static_cast<float>(point[0]), static_cast<float>(this->minpt[0])),
                       SbMin(static_cast<float>(point[1]), static_cast<float>(this->minpt[1])),
                       SbMin(static_cast<float>(point[2]), static_cast<float>(this->minpt[2])));
  this->maxpt.setValue(SbMax(static_cast<float>(point[0]), static_cast<float>(this->maxpt[0])),
                       SbMax(static_cast<float>(point[1]), static_cast<float>(this->maxpt[1])),
                       SbMax(static_cast<float>(point[2]), static_cast<float>(this->maxpt[2])));
  }
}

/*!
  Extend the boundaries of the box by the given \a box parameter. This
  is equal to calling extendBy() twice with the corner points.
 */
void
SbBox3f::extendBy(const SbBox3f & box)
{
  if (box.isEmpty()) { return; }

  if (this->isEmpty()) {
    *this = box;
  }
  else {
    this->extendBy(box.minpt);
    this->extendBy(box.maxpt);
  }
}

/*!
  Check if the given point lies within the boundaries of this box.
 */
SbBool
SbBox3f::intersect(const SbVec3f & point) const
{
  return !(point[0] < this->minpt[0] ||
           point[0] > this->maxpt[0] ||
           point[1] < this->minpt[1] ||
           point[1] > this->maxpt[1] ||
           point[2] < this->minpt[2] ||
           point[2] > this->maxpt[2]);
}

/*!
  Check if the given \a box lies wholly or partly within the boundaries
  of this box.
 */
SbBool
SbBox3f::intersect(const SbBox3f & box) const
{
  if ((box.maxpt[0] < this->minpt[0]) ||
     (box.maxpt[1] < this->minpt[1]) ||
     (box.maxpt[2] < this->minpt[2]) ||
     (box.minpt[0] > this->maxpt[0]) ||
     (box.minpt[1] > this->maxpt[1]) ||
     (box.minpt[2] > this->maxpt[2])) return FALSE;
  return TRUE;
}

/*!
  \fn void SbBox3f::getBounds(float & minx, float & miny, float & minz, float & maxx, float & maxy, float & maxz) const

  Returns the box boundaries.

  \sa setBounds().
*/

/*!
  \fn void SbBox3f::getBounds(SbVec3f & minobj, SbVec3f & maxobj) const

  Returns the box corner points.

  \sa setBounds().
*/

/*!
  \fn void SbBox3f::getOrigin(float & x0, float & y0, float & z0) const

  Returns the coordinates of the box origin (i.e. the lower left corner).

  \sa getMin().
*/

/*!
  \fn void SbBox3f::getSize(float & dx, float & dy, float & dz) const

  Returns width, height and depth of box.
*/

/*!
  \fn SbVec3f SbBox3f::getSize(void) const

  Returns width, height and depth of box as a 3D vector.

  \since Coin 3.0
*/

/*!
  Marks this as an empty box.

  \sa isEmpty().
 */
void
SbBox3f::makeEmpty(void)
{
  this->minpt.setValue(std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
  this->maxpt.setValue(-std::numeric_limits<float>::max(), -std::numeric_limits<float>::max(), -std::numeric_limits<float>::max());
}

/*!
  \fn SbBool SbBox3f::isEmpty(void) const

  Check if this has been marked as an empty box.

  \sa makeEmpty().
*/

/*!
  \fn SbBool SbBox3f::hasVolume(void) const

  Check if the box has been correctly specified and by that virtue
  has volume.
*/

/*!
  \fn float SbBox3f::getVolume(void) const

  Check if the box has "positive" volume, i.e. the lower left corner is
  actually lower and more left than the maximum point.
*/

/*!
  Find the span of the box in the given direction (i.e. how much room in
  the given direction the box needs). The distance is returned as the minimum
  and maximum distance from origo to the closest and furthest plane defined
  by the direction vector and each of the box' corners. The difference
  between these values gives the span.
*/
void
SbBox3f::getSpan(const SbVec3f & dir, float & dmin, float & dmax) const
{
  float dist, mindist = std::numeric_limits<float>::max(), maxdist = -std::numeric_limits<float>::max();
  SbVec3f points[2] = {this->minpt, this->maxpt};
  SbVec3f corner;
  SbVec3f normdir(dir);
  if (normdir.normalize() == 0.0f) {
#if COIN_DEBUG
    SoDebugError::postWarning("SbBox3f::getSpan",
                              "The direction is a null vector.");
#endif // COIN_DEBUG

    dmin = dmax = 0.0f;
    return;
  }

  for (int i=0; i < 8; i++) {
    //Find all corners the "binary" way :-)
    corner.setValue(points[(i&4)>>2][0], points[(i&2)>>1][1], points[i&1][2]);

    // a = dir
    // b = corner-[0, 0, 0]
    // v = dir/|dir|
    //
    // The dot product formula (1) gives the formula we use (2).
    //
    // (1)  a * b = |a|*|b| * cos(angle(a, b))
    //
    // (2)  distance = v * b
    //
    // This dot product (2) gives the distance from origo to the plane
    // defined by normdir and corner.
    dist=normdir.dot(corner);
    if (dist < mindist) mindist = dist;
    if (dist > maxdist) maxdist = dist;
  }

  dmin = mindist;
  dmax = maxdist;
}

/*!
  Transform the box by the matrix, and change its boundaries to contain
  the transformed box.

  Doesn't touch illegal/empty boxes.
*/
void
SbBox3f::transform(const SbMatrix & matrix)
{
#if COIN_DEBUG
  if (this->isEmpty()) {
    SoDebugError::postWarning("SbBox3f::transform",
                              "The box is not valid!");
    return;
  }
#endif // COIN_DEBUG

  SbVec3f dst;
  SbVec3f points[2] = {this->minpt, this->maxpt};
  SbVec3f corner;
  SbBox3f newbox;

  //transform all the corners and include them into the new box.
  for (int i=0;i<8;i++) {
    //Find all corners the "binary" way :-)
    corner.setValue(points[(i&4)>>2][0], points[(i&2)>>1][1], points[i&1][2]);
    matrix.multVecMatrix(corner, dst);
    newbox.extendBy(dst);
  }
  this->setBounds(newbox.minpt, newbox.maxpt);
}

/*!
  Dump the state of this object to the \a file stream. Only works in
  debug version of library, method does nothing in an optimized compile.
 */
void
SbBox3f::print(FILE * fp) const
{
#if COIN_DEBUG
  SbVec3f minv, maxv;
  this->getBounds(minv, maxv);
  minv.print(fp);
  fprintf(fp, " ");
  maxv.print(fp);
#endif // COIN_DEBUG
}

/*!
  \fn int operator == (const SbBox3f & b1, const SbBox3f & b2)
  \relates SbBox3f

  Check \a b1 and \a b2 for equality.
*/

/*!
  \fn int operator != (const SbBox3f & b1, const SbBox3f & b2)
  \relates SbBox3f

  Check \a b1 and \a b2 for inequality.
*/

/*!
  Check if the box is outside the view volume defined by the \a mvp
  matrix. Sets \a cullbits according to which planes we're inside or
  outside. Bit 0 (0x1) is cleared when box is completely inside left
  and right clipping planes. Bit 1 (0x2) is cleared when box is inside
  top and bottom clipping planes. Bit 2 (0x4) is cleared when box is
  inside near and far clipping planes.

  Returns \c TRUE if box is completely outside one of the clipping
  planes. \c FALSE otherwise.
*/
SbBool
SbBox3f::outside(const SbMatrix & mvp, int & cullbits) const
{
  // FIXME: this function is untested (code written by
  // pederb). 20000615 mortene.

  int i;
  SbVec3f tmp;
  SbVec3f clip[8];
  for (i = 0; i < 8; i++) {
    tmp[0] = i & 4 ? this->minpt[0] : this->maxpt[0];
    tmp[1] = i & 2 ? this->minpt[1] : this->maxpt[1];
    tmp[2] = i & 1 ? this->minpt[2] : this->maxpt[2];
    mvp.multVecMatrix(tmp, clip[i]);
  }
  for (int j = 0; j < 3; j++) {
    if (cullbits & (1<<j)) {
      int inside = 0;
      int outsideneg = 0;
      int outsidepos = 0;
      for (i = 0; i < 8; i++) {
        float val = clip[i][j];
        if (val < -1.0f) outsideneg++;
        else if (val > 1.0f) outsidepos++;
        else inside++;
      }
      if (outsidepos == 8) return TRUE;
      if (outsideneg == 8) return TRUE;
      if (inside == 8) cullbits ^= (1<<j);
    }
  }
  return FALSE;
}

/*!
  Return the point on the box closest to the given \a point.
*/
SbVec3f
SbBox3f::getClosestPoint(const SbVec3f & point) const
{
  SbVec3f closest = point;

  SbVec3f center = this->getCenter();
  float devx = closest[0] - center[0];
  float devy = closest[1] - center[1];
  float devz = closest[2] - center[2];
  float halfwidth = (this->maxpt[0] - this->minpt[0]) / 2.0f;
  float halfheight = (this->maxpt[1] - this->minpt[1]) / 2.0f;
  float halfdepth = (this->maxpt[2] - this->minpt[2]) / 2.0f;

  // Move point to be on the nearest plane of the box.
  if ((fabs(devx) > fabs(devy)) && (fabs(devx) > fabs(devz)))
    closest[0] = center[0] + halfwidth * ((devx < 0.0f) ? -1.0f : 1.0f);
  else if (fabs(devy) > fabs(devz))
    closest[1] = center[1] + halfheight * ((devy < 0.0f) ? -1.0f : 1.0f);
  else
    closest[2] = center[2] + halfdepth * ((devz < 0.0f) ? -1.0f : 1.0f);

  // Clamp to be inside box.
  closest[0] = SbMin(SbMax(closest[0], this->minpt[0]), this->maxpt[0]);
  closest[1] = SbMin(SbMax(closest[1], this->minpt[1]), this->maxpt[1]);
  closest[2] = SbMin(SbMax(closest[2], this->minpt[2]), this->maxpt[2]);

  return closest;
}
